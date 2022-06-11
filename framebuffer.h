#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#define FB_BLACK        0
#define FB_BLUE         1
#define FB_GREEN        2
#define FB_CYAN         3
#define FB_RED          4
#define FB_MAGENTA      5
#define FB_BROWN        6
#define FB_LIGHTGREY    7
#define FB_DARKGREY     8
#define FB_LIGHTBLUE    9
#define FB_LIGHTGREEN   10
#define FB_LIGHTCYAN    11
#define FB_LIGHTRED     12
#define FB_LIGHTMAGENTA 13
#define FB_LIGHTBROWN   14
#define FB_WHITE        15

#define MAX_FB_POS      2000

/** fb_write_cell:
 *  Writes a character with the given foreground and background to position i
 *  in the framebuffer.
 *
 *  @param i  The location in the framebuffer
 *  @param c  The character
 *  @param fg The foreground color
 *  @param bg The background color
 */
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);


/** fb_move_cursor:
    *  Moves the cursor of the framebuffer to the given position
    *
    *  @param pos The new position of the cursor
    */
void fb_move_cursor(unsigned short pos);


/** write:
    *  Writes data in buf up to len to the screen
    *
    *  @param buf Pointer to data
    *  @param len Length of data
    */
int fb_write(char *buf, unsigned int len);

#endif
