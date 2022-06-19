#include "utils.h"

#define REALLY_BIG_NUMBER 1000000000

unsigned int itos(unsigned int num, char * buf)
{
    unsigned int n = 0;
    char foundFirstNum = 0;
    for (unsigned int i = REALLY_BIG_NUMBER; i > 0; i = i / 10)
    {
        char tmp = num / i;
        if (foundFirstNum || tmp > 0) {
            foundFirstNum = 1;
            buf[n++] = tmp + 48; // gives number 0-9 in ascii
            num = num % i;
        }
    }
    
    return n;
}
