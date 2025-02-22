#include <stdio.h>
#include <fcntl.h>
#include "tests.h"
#include "utils.h"
#include "libasm.h"

char    *src = "Meme 42";

bool    check_new_addr(void *str)
{
    return str != src && str != NULL;
}

int	tester_strdup()
{
    char    *res;

    printf("\n-- strdup --\n");
    
    res = ft_strdup(src);
    assert_fn (
        res, check_new_addr,
        "new address of duplicated string", "new address should not be NULL, and should return the malloc buffer"
    );
    if (res)
        free(res);

    res = ft_strdup(src);
    assert_str (
        res, src,
        "copied value of strdup", NULL
    );
    if (res)
        free(res);

    res = ft_strdup("");
    assert_str (
        res, "",
        "copied value of empty string", NULL
    );
    if (res)
        free(res);

    res = ft_strdup(NULL);
    assert_str (
        res, NULL,
        "copied value of NULL", NULL
    );
    if (res)
        free(res);

    return 0;
}
