#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "tests.h"
#include "utils.h"
#include "libasm.h"

int	tester_strcpy()
{
    char    *src = "Meme 42";
    char    *dest = malloc(strlen(src));
    char    *res;
    printf("\n-- ft_strcpy --\n");

    res = ft_strcpy(dest, src);
    assert_str (
        dest, src,
        "copied value of strcpy", NULL
    );

    res = ft_strcpy(dest, src);
    assert_str (
        res, dest,
        "return value of strcpy", NULL
    );

    free(dest);
    return 0;
}
