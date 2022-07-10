#include "framebuffer.h"
#include "serial.h"
#include "printk.h"
//#include "gdt.h"

int kmain()
{
    struct gdt {
        unsigned int address;
        unsigned short size;
    } __attribute__((packed));
    printk("Hello World! Bush did %d\n", 911);

    return 0;
}
