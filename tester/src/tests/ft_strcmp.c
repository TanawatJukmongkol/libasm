#include <stdio.h>
#include <fcntl.h>
#include "tests.h"
#include "utils.h"
#include "libasm.h"


static bool    less_than_zero(void *res)
{
    return *((int*)res) < 0;
}

static bool    more_than_zero(void *res)
{
    return *((int*)res) > 0;
}

int	tester_strcmp()
{
    int res;
	printf("\n-- ft_strcmp --\n");

	assert_int (
		ft_strcmp("abc", "abc"), 0,
		"strcmp of \"abc\", and \"abc\"", NULL
	);
    res = ft_strcmp("abc", "ab");
	assert_fn (
		(void *)&res, more_than_zero,
		"strcmp of \"abc\", and \"ab\"", "compare must be more than zero."
	);
    res = ft_strcmp("abc", "ac");
	assert_fn (
		(void *)&res, less_than_zero,
		"strcmp of \"abc\", and \"ac\"", "compare must be less than zero."
	);
	return 0;
}
