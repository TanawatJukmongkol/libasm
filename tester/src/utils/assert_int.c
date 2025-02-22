#include <stdio.h>
#include "utils.h"
#include "ansi_color.h"

int assert_int(int res, int expect, char *title, char *msg)
{
    char    buff[100];
    if (res == expect)
    {
        printf(GRN "[OK] %s " CYN "assertion passed!\n" CRESET, title);
        return 0;
    }
    if (!msg)
    {
        sprintf(buff, "expect %d, but got %d." CRESET, expect, res);
        msg = buff;
    }
    printf(RED "[OK] %s " YEL "assertion failed: %s\n" CRESET, title, msg);
    return 1;
}
