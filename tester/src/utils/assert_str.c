#include "utils.h"

int assert_str(char *res, char *expect, char *title, char *msg)
{
    char    buff[100];
    if (strcmp(res, expect) == 0)
    {
        printf("[OK] %s assertion passed!\n", title);
        return 0;
    }
    if (!msg)
    {
        sprintf(buff, "expect \"%s\".", expect);
        msg = buff;
    }
    printf("[KO] %s assertion failed: %s\n", title, msg);
    return 1;
}
