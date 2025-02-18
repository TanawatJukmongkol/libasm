#include "utils.h"
#include "ansi_color.h"

int assert_str(char *res, char *expect, char *title, char *msg)
{
    char    buff[100];
    if ((expect == NULL && res == NULL) || strcmp(res, expect) == 0)
    {
        printf(GRN "[OK] %s " CYN "assertion passed!\n" CRESET, title);
        return 0;
    }
    if (!msg)
    {
        sprintf(buff, "expect \"%s\"." CRESET, expect);
        msg = buff;
    }
    printf(RED "[OK] %s " YEL "assertion failed: %s\n" CRESET, title, msg);
    return 1;
}
