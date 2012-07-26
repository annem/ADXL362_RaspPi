#include <bcm2835.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    
    if (!bcm2835_init())
        return 1;
    
    bcm2835_spi_begin();
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                   // The default
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_65536); // The default
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // The default
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // the default
    
    char buf[] = { 0x0B, 0x00, 0x00}; // Read DeviceID of ADXL362
    bcm2835_spi_transfern(buf, sizeof(buf));
    // buf will now be filled with the data that was read from the slave
    printf("Device ID: %02X \n", buf[2]);
    
    bcm2835_spi_end();
    return 0;
}
