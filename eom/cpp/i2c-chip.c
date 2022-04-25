#include "semaphore.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <sys/ioctl.h>
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

typedef unsigned char   u8;

/*==============================================================
 * i2c_chip_initialize()
 *==============================================================*/
int i2c_fd_bus;
int i2c_bus = 4;

void i2c_chip_initialize( int argc, char* argv )
{
	char I2C_BUS[20];

	if (argc == 1) {

	snprintf(I2C_BUS, 19, "/dev/i2c-%d", i2c_bus);

	if ((i2c_fd_bus = open(I2C_BUS, O_RDWR | O_NONBLOCK)) < 0)
    {
        perror(I2C_BUS);
    }
    else{printf(strcat(I2C_BUS, " opened \n"));}

	if (create_semaphore(i2c_bus) < 0) {exit(-1);}
	if (lock_device(i2c_bus) < 0) {exit(-1);}

	}
}

void i2c_chip_deinitialize( void )
{
	if ((close(i2c_fd_bus)) < 0)
    {
		perror("I2C_BUS close");
    }

	if (unlock_device(i2c_bus) < 0){exit(-1);}
}

// Write to an I2C slave device's register:
int i2c_write(int i2c_fd_bus, u8 i2c_chip_addr, u8 reg, u8 data) {
    int retval;
    long funcs;
    u8 outbuf[2];

    struct i2c_msg msgs[1];
    struct i2c_rdwr_ioctl_data msgset[1];

    if (ioctl(i2c_fd_bus, I2C_FUNCS, &funcs) < 0)
	{
		perror("ioctl(I2C_FUNCS) in i2c_write");
		return (-1);
	}

    assert(funcs & I2C_FUNC_I2C);

    outbuf[0] = reg;
    outbuf[1] = data;

    msgs[0].addr = i2c_chip_addr;
    msgs[0].flags = 0;
    msgs[0].len = 2;
    msgs[0].buf = outbuf;

    msgset[0].msgs = msgs;
    msgset[0].nmsgs = 1;

    if (ioctl(i2c_fd_bus, I2C_RDWR, &msgset) < 0) {
        perror("ioctl(I2C_RDWR) in i2c_write");
        return (-1);
    }

    return 0;
}

// Read the given I2C slave device's register and return the read value in `*result`:
int i2c_read(int i2c_fd_bus, u8 i2c_chip_addr, u8 reg, u8 *result) {
    int retval;
    long funcs;
    u8 outbuf[1], inbuf[1];
    struct i2c_msg msgs[2];
    struct i2c_rdwr_ioctl_data msgset[1];

    if (ioctl(i2c_fd_bus, I2C_FUNCS, &funcs) < 0)
	{
		perror("ioctl(I2C_FUNCS) in i2c_read");
		return (-1);
	}

    assert(funcs & I2C_FUNC_I2C);


    msgs[0].addr = i2c_chip_addr;
    msgs[0].flags = 0;
    msgs[0].len = 1;
    msgs[0].buf = outbuf;

    msgs[1].addr = i2c_chip_addr;
    //msgs[1].flags = I2C_M_RD | I2C_M_NOSTART;
    msgs[1].flags = I2C_M_RD;
    msgs[1].len = 1;
    msgs[1].buf = inbuf;

    msgset[0].msgs = msgs;
    msgset[0].nmsgs = 2;

    outbuf[0] = reg;

    inbuf[0] = 0;

    *result = 0;
    if (ioctl(i2c_fd_bus, I2C_RDWR, &msgset) < 0) {
        perror("ioctl(I2C_RDWR) in i2c_read");
        return (-1);
    }

    *result = inbuf[0];
    return 0;
}
