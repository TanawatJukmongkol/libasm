#include "utils.h"

int assert_int(int res, int expect, char *title, char *msg)
{
    char    buff[100];
    if (res == expect)
    {
        printf("[OK] %s assertion passed!\n", title);
        return 0;
    }
    if (!msg)
    {
        sprintf(buff, "expect %d.", expect);
        msg = buff;
    }
    printf("[KO] %s assertion failed: %s\n", title, msg);
    return 1;
}
