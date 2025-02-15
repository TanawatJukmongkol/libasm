#include "libasm.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	printf("%d\n", ft_strcmp("a", ""));
	printf("%d\n", strcmp("a", ""));
	return 0;
}
