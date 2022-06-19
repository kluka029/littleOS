#include "framebuffer.h"
#include "serial.h"
#include "printk.h"

int kmain()
{
    printk("Hello World! Bush did %d\n", 911);

    return 0;
}
