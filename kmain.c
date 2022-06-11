#include "framebuffer.h"
#include "serial.h"
#include "printk.h"

int kmain()
{
    fb_write("H e l l o  W o r l d !", 22);
    
    serial_configure_baud_rate(SERIAL_COM1_BASE, 1); // sets baud rate to 115200
    serial_configure_line(SERIAL_COM1_BASE);
    serial_configure_buffer(SERIAL_COM1_BASE);
    serial_configure_modem(SERIAL_COM1_BASE);
    serial_write(SERIAL_COM1_BASE, "H e l l o W o r l d !", 22);
    
    char * buf = "123";
    
    printk(buf, 2,3,4,5,6,7,8);
    
    serial_write(SERIAL_COM1_BASE, buf, 3);
    
    return 0;
}
