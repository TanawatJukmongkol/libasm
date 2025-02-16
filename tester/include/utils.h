#ifndef	UTILS_H
# define UTILS_H

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include "libasm.h"

int assert_int(int res, int expect, char *title, char *msg);
int assert_str(char *res, char *expect, char *title, char *msg);

#endif