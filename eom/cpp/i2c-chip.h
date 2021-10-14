typedef unsigned char u8;

extern int i2c_fd_bus;
extern int i2c_bus;

void i2c_chip_initialize( int argc, char* argv );
void i2c_chip_deinitialize( void );

int i2c_write(int i2c_fd_bus, u8 i2c_chip_addr, u8 reg, u8 data); 
int i2c_read(int i2c_fd_snsr, u8 i2c_chip_addr, u8 reg, u8 *result);
