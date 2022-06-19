/** printk(defined in printk.s):
 * Works just like printf, just done in a hacky way and less efficient.
 * Supported types:
 *      int(%d)
 *      char(%c)
 *      float(%f)
 * 
 *  @param buf      Pointer to data to write to serial
 *  @param arg*     Data to insert into string.
 */
void printk(/*char *buf, arg1, arg2, arg3, ...*/);
