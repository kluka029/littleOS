#include "framebuffer.h"
#include "io.h"

/* Pointer to beginning of framebuffer (80 col x 25 row). Index zero
   corresponds to col=0, row=0. Index 1 corresponds to col=1, row=0...*/
static char *fb = (char *)0x000B8010;


void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
{
    fb[2*i] = c;
    fb[2*i + 1] = (fg << 4) | bg;
}


void fb_move_cursor(unsigned short pos)
{
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,    pos & 0x00FF);
}


int fb_write(char *buf, unsigned int len) //TODO: figure out how to scroll screen/move framebuffer offset.
{
    static unsigned int pos = 0;
    for (unsigned int i = 0; i < len; i++)
    {
        fb_write_cell(pos++, buf[i], FB_BLACK, FB_WHITE);
        //fb_move_cursor(pos); TODO: figure out why framebuffer is offset by 5
    }

    return 0;
}
