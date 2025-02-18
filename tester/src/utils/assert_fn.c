#include "utils.h"
#include "ansi_color.h"

int assert_fn(void *res, bool (*expect)(void *res), char *title, char *msg)
{
    char    buff[100];
    if (expect(res))
    {
        printf(GRN "[OK] %s " CYN "assertion passed!\n" CRESET, title);
        return 0;
    }
    printf(RED "[OK] %s " YEL "assertion failed: %s\n" CRESET, title, msg);
    return 1;
}
