#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <sstream>
#include <string>

#include "xvc_ioctl.h"
#include "semaphore.h"

#define KINTEX7_ID 0x03647093
#define VIRTEX7_ID 0x33691093
#define MAX_SHIFT_BUF 1024

#define BYTE_ALIGN(a) ((a + 7) / 8)
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

const uint8_t bitRevTable[256] =
{
    0x00, 0x80, 0x40, 0xc0, 0x20, 0xa0, 0x60, 0xe0,
    0x10, 0x90, 0x50, 0xd0, 0x30, 0xb0, 0x70, 0xf0,
    0x08, 0x88, 0x48, 0xc8, 0x28, 0xa8, 0x68, 0xe8,
    0x18, 0x98, 0x58, 0xd8, 0x38, 0xb8, 0x78, 0xf8,
    0x04, 0x84, 0x44, 0xc4, 0x24, 0xa4, 0x64, 0xe4,
    0x14, 0x94, 0x54, 0xd4, 0x34, 0xb4, 0x74, 0xf4,
    0x0c, 0x8c, 0x4c, 0xcc, 0x2c, 0xac, 0x6c, 0xec,
    0x1c, 0x9c, 0x5c, 0xdc, 0x3c, 0xbc, 0x7c, 0xfc,
    0x02, 0x82, 0x42, 0xc2, 0x22, 0xa2, 0x62, 0xe2,
    0x12, 0x92, 0x52, 0xd2, 0x32, 0xb2, 0x72, 0xf2,
    0x0a, 0x8a, 0x4a, 0xca, 0x2a, 0xaa, 0x6a, 0xea,
    0x1a, 0x9a, 0x5a, 0xda, 0x3a, 0xba, 0x7a, 0xfa,
    0x06, 0x86, 0x46, 0xc6, 0x26, 0xa6, 0x66, 0xe6,
    0x16, 0x96, 0x56, 0xd6, 0x36, 0xb6, 0x76, 0xf6,
    0x0e, 0x8e, 0x4e, 0xce, 0x2e, 0xae, 0x6e, 0xee,
    0x1e, 0x9e, 0x5e, 0xde, 0x3e, 0xbe, 0x7e, 0xfe,
    0x01, 0x81, 0x41, 0xc1, 0x21, 0xa1, 0x61, 0xe1,
    0x11, 0x91, 0x51, 0xd1, 0x31, 0xb1, 0x71, 0xf1,
    0x09, 0x89, 0x49, 0xc9, 0x29, 0xa9, 0x69, 0xe9,
    0x19, 0x99, 0x59, 0xd9, 0x39, 0xb9, 0x79, 0xf9,
    0x05, 0x85, 0x45, 0xc5, 0x25, 0xa5, 0x65, 0xe5,
    0x15, 0x95, 0x55, 0xd5, 0x35, 0xb5, 0x75, 0xf5,
    0x0d, 0x8d, 0x4d, 0xcd, 0x2d, 0xad, 0x6d, 0xed,
    0x1d, 0x9d, 0x5d, 0xdd, 0x3d, 0xbd, 0x7d, 0xfd,
    0x03, 0x83, 0x43, 0xc3, 0x23, 0xa3, 0x63, 0xe3,
    0x13, 0x93, 0x53, 0xd3, 0x33, 0xb3, 0x73, 0xf3,
    0x0b, 0x8b, 0x4b, 0xcb, 0x2b, 0xab, 0x6b, 0xeb,
    0x1b, 0x9b, 0x5b, 0xdb, 0x3b, 0xbb, 0x7b, 0xfb,
    0x07, 0x87, 0x47, 0xc7, 0x27, 0xa7, 0x67, 0xe7,
    0x17, 0x97, 0x57, 0xd7, 0x37, 0xb7, 0x77, 0xf7,
    0x0f, 0x8f, 0x4f, 0xcf, 0x2f, 0xaf, 0x6f, 0xef,
    0x1f, 0x9f, 0x5f, 0xdf, 0x3f, 0xbf, 0x7f, 0xff,
};

static int fXVCMode = 0;
// static char* char_path = "/dev/xilinx_xvc_driver";

void error(const char *msg)
{
  perror(msg);
  exit(0);
}


int shiftJtag(int fd, char* tms, char* tdi, char* tdo, int32_t length)
{
  struct xil_xvc_ioc xvc_ioc;
  int n;
  char* buf;
  int32_t num_bits = length;
  int32_t num_bytes = (num_bits+7)/8;

  if (fXVCMode) {
  std::string shiftcmd = "shift:";

  n = write(fd,shiftcmd.c_str(),strlen(shiftcmd.c_str()));
  if (n < 0)
    {
      error("ERROR writing to socket");
      return -1;
    }

  write(fd,&num_bits, 4);
  if (n < 0)
    {
      error("ERROR writing to socket");
      return -1;
    }

  // write TMS,TDI buffers
  buf = (char *)malloc(num_bytes*2);
  if (buf == NULL)
    {
      error("ERROR allocating memory buffer");
      return -1;
    }
  bzero(buf,num_bytes*2);
  memcpy(buf, tms,num_bytes);
  memcpy(buf+num_bytes, tdi, num_bytes);
  n = write(fd,buf,num_bytes*2);
  if (n < 0)
    {
      error("ERROR writing to socket");
      return -1;
    }

  // read TDO buffer
  bzero(buf,num_bytes);
  n = read(fd,buf,num_bytes);
  if (n < 0)
    {
      error("ERROR reading from socket");
      return -1;
    }

  if (tdo != NULL)
    {
      memcpy(tdo, buf, num_bytes);
      printf("readback:%d bytes\n",n);
    }

  free(buf);
  } else {
    n = num_bytes;
    xvc_ioc.tdi_buf = (unsigned char*)tdi;
    xvc_ioc.tms_buf = (unsigned char*)tms;
    xvc_ioc.tdo_buf = (unsigned char*)tdo;
    if (xvc_ioc.tdo_buf == NULL)
      xvc_ioc.tdo_buf = (unsigned char *)malloc(num_bytes);
    if (xvc_ioc.tdo_buf != NULL) 
      memset(xvc_ioc.tdo_buf, 0, num_bytes);

    // set up ioctl codes
    xvc_ioc.opcode = 0x01; // 0x01 for normal, 0x02 for bypass
    xvc_ioc.length = num_bits;

    // run the test
    int ret = ioctl(fd, XDMA_IOCXVC, &xvc_ioc);
    if (ret < 0)
    {
        printf("Could not run the command test bitlen %d\n", num_bits);
        printf("Error: %s\n", strerror(errno));
        return -1;
    }
   

  }

  return n;
}

int flipbytes(unsigned char* src, unsigned char* flipped, int size)
{
   for (int i=0; i<size; i++)
    {
     *(flipped+i) = bitRevTable[*(src+i)];
      // printf ("0x%02x 0x%02x\n", *(src+i), *(flipped+i));
    }
  return size;
}

int getinfo(int sockfd, char * buf)
{
  int n;
  char buffer[256];
  std::string getinfo = "getinfo\n";

  bzero(buffer,256);
  memcpy(buffer, getinfo.c_str(), strlen(getinfo.c_str()));
  n = write(sockfd,buffer,strlen(buffer));
  if (n < 0)
    {
      error("ERROR writing to socket");
      return -1;
    }

  bzero(buffer,256);
  n = read(sockfd,buffer,255);
  if (n < 0)
    {
      error("ERROR reading from socket");
      return -1;
    }

  memcpy(buf, buffer, n);

  return 0;
}

uint32_t read_idcode(int sockfd)
{
  uint32_t ID = 0;

  int n;
  char tms_vec[4];
  char tdi_vec[4];
  char tdo_vec[4];

  int32_t num_bits = 10;

  tms_vec[0] = 0xDF;
  tms_vec[1] = 0x0;
  tdi_vec[0] = 0x0;
  tdi_vec[1] = 0x0;

  shiftJtag(sockfd, tms_vec, tdi_vec, NULL, num_bits);

  num_bits = 10;
  tms_vec[0] = 0xE0;
  tms_vec[1] = 0x00;
  tdi_vec[0] = 0x9;
  tdi_vec[1] = 0x0;

  shiftJtag(sockfd, tms_vec, tdi_vec, NULL, num_bits);


  num_bits = 32;
  for (int i=0; i<4; i++)
    {
      tms_vec[i]=0;
      tdi_vec[i]=0;
    }
  tms_vec[3] = 0x80;

  n = shiftJtag(sockfd, tms_vec, tdi_vec, tdo_vec, num_bits);
  if (n>0)
    {
      for (int i=n-1; i>=0; i--)
        {
          // ID = ID << 8;
          // printf("%02x ", tdo_vec[i]);
          ID |= ((unsigned char)tdo_vec[i] << (8*i));

        }
    }

  num_bits = 5;
  tms_vec[0] = 0x1F;
  tdi_vec[0] = 0;

  shiftJtag(sockfd, tms_vec, tdi_vec, NULL, num_bits);
  return ID;
}

int sleepJtag(int sockfd, int32_t delay)
{
  int cnt = 0;
  int num_bits = delay;
  char * tck = (char *)malloc(MAX_SHIFT_BUF);
  bzero(tck, MAX_SHIFT_BUF);
  
  while (cnt < delay) {  
     num_bits = (delay < MAX_SHIFT_BUF*8)?delay:MAX_SHIFT_BUF*8;
     shiftJtag(sockfd, tck, tck, NULL, num_bits);
     cnt += num_bits;
  }

  free(tck);

  return delay;
}

int program_binfile(int sockfd, char* binfile)
{
  int n=0;

  char tms_vec[4];
  char tdi_vec[4];
  char tdo_vec[4];

  // TLR + enter SHIFT-IR
  int32_t num_bits = 10;
  tms_vec[0] = 0xDF;
  tms_vec[1] = 0x0;
  tdi_vec[0] = 0x0;
  tdi_vec[1] = 0x0;

  shiftJtag(sockfd, tms_vec, tdi_vec, NULL, num_bits);

  // JPROGRAM + enter RTI state
  num_bits = 11;
  tms_vec[0] = 0xE0;
  tms_vec[1] = 0x01;
  tdi_vec[0] = 0xB; // JPROGRAM
  tdi_vec[1] = 0x0;

  shiftJtag(sockfd, tms_vec, tdi_vec, NULL, num_bits);

  // CFG_IN + UPDATE-IR 
  num_bits = 8;
  tms_vec[0] = 0x60;
  tdi_vec[0] = 0x5; // CFG_IN

  shiftJtag(sockfd, tms_vec, tdi_vec, NULL, num_bits);

  // delay for 10ms  or will need to change to 10000/20000 TCK in RTI state
  usleep(40000);
  sleepJtag(sockfd, 100000);

  // SELECT-DR + SHIFT-DR
  num_bits = 3;
  tms_vec[0] = 0x1; 
  tdi_vec[0] = 0x0;

  shiftJtag(sockfd, tms_vec, tdi_vec, NULL, num_bits);

  // Shift in the FPGA bitstream from binfile
  int cnt = 0;
  int nread = MAX_SHIFT_BUF;
  int fd = open(binfile, O_RDONLY);
  if (fd<0) {
    error("ERROR opening binfile");
    return -1;
  }
  char * tdi_buf = (char *)malloc(nread);
  char * tms_buf = (char *)malloc(nread);
  char * buf = (char *)malloc(nread);
  if ((tms_buf != NULL) && (tdi_buf != NULL)) {
    bzero(tms_buf, nread);
    bzero(tdi_buf, nread);
    while ((nread = read(fd,buf, MAX_SHIFT_BUF)) > 0){
      if (nread < MAX_SHIFT_BUF) {
         // printf("last bit\n");
         *(tms_buf+nread-1) = 0x80;
      }
      flipbytes((unsigned char*)buf,(unsigned char*)tdi_buf,nread);
      shiftJtag(sockfd, tms_buf, tdi_buf, NULL, nread*8);
      bzero(tdi_buf, nread);
      cnt += nread;
      // printf("\n");
      if (fXVCMode) 
        printf("\rsent: %d bytes %d bits",cnt, cnt*8);
    }
    printf("\nRead %d bytes from binfile %s\n", cnt, binfile);
  }
  if (fd) close(fd);


  // UPDATE-DR + RTI + SELECT-IR + SHIFT-IR
  num_bits = 6;
  tms_vec[0] = 0xD;
  tdi_vec[0] = 0x0;

  shiftJtag(sockfd, tms_vec, tdi_vec, NULL, num_bits);

  // JSTART + UPDATE-IR + moveto RTI
  num_bits = 7;
  tms_vec[0] = 0x60;
  tdi_vec[0] = 0x0C;
  
  shiftJtag(sockfd, tms_vec, tdi_vec, NULL, num_bits);
  
  // delay for 2ms  or will need to change to 2000 TCK in RTI state
  usleep(10000);
  sleepJtag(sockfd, 2000);

  // move to TLR
  num_bits = 3;
  tms_vec[0] = 0x7;
  tdi_vec[0] = 0x0;

  shiftJtag(sockfd, tms_vec, tdi_vec, NULL, num_bits);
  
  return n;
}

int main(int argc, char *argv[])
{
  int sockfd, portno, n, fd;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char * binfile = NULL;
  std::string char_path = "/dev/xilinx_xvc_driver";
  char buffer[256];

  if (fXVCMode) 
  {
 
  if (argc < 3)
    {
      fprintf(stderr,"usage %s hostname port binfile\n", argv[0]);
      exit(0);
    }

  portno = atoi(argv[2]);
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
    error("ERROR opening socket");
  server = gethostbyname(argv[1]);
  if (server == NULL)
    {
      fprintf(stderr,"ERROR, no such host\n");
      exit(0);
    }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,
        (char *)&serv_addr.sin_addr.s_addr,
        server->h_length);
  serv_addr.sin_port = htons(portno);
  if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
    error("ERROR connecting");

  if (argc == 4)
    {
      binfile = argv[3];
      printf("Load bitstream from %s\n", binfile);
    }

  // getinfo from XVC server
  bzero(buffer,256);
  getinfo(sockfd, buffer);
  printf("%s\n", buffer);

  // read FPGA ID
  printf("IDCODE: 0x%X\n", read_idcode(sockfd));

  if (binfile != NULL)
    {
      program_binfile(sockfd, binfile);
    }

  close(sockfd);
}
else {

    if (argc < 2)
    {
      fprintf(stderr,"usage %s device_file binfile\n", argv[0]);
      exit(0);
    }
    char_path = argv[1];
    int ind = (int) strtol(&argv[1][strlen(argv[1])-1], NULL, 10);
    create_semaphore(ind);
    lock_device(ind);
    // try opening the driver
    fd = open(char_path.c_str(), O_RDWR | O_SYNC);
    if (fd <= 0)
    {
        printf("Could not open driver at %s\n", char_path.c_str());
        printf("Error: %s\n", strerror(errno));
        return 0;
    }

    if (argc == 3)
    {
      binfile = argv[2];
      printf("Load bitstream from %s\n", binfile);
    }

    // read FPGA ID
    printf("IDCODE: 0x%X\n", read_idcode(fd));

    if (binfile != NULL)
    {
      program_binfile(fd, binfile);
    }

    close(fd);
    unlock_device(ind);
}
  return 0;
}
