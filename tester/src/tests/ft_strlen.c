#include "utils.h"
#include <signal.h>
#include <stdbool.h>

bool	sigv = false;

void	sig_handle(int sigid)
{
	sigv = true;
}

int	tester_strlen()
{
	printf("\n-- ft_strlen --\n");

	assert_int (
		ft_strlen("abc"), 3,
		"strlen of \"abc\"", NULL
	);
	assert_int (
		ft_strlen(""), 0,
		"strlen of \"\"", NULL
	);
	signal(SIGSEGV, sig_handle);
	ft_strlen(NULL);
	assert_int (
		sigv, false,
		"strlen of NULL", "SIGSEGV."
	);
	return 0;
}
