#ifndef	UTILS_H
# define UTILS_H

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "libasm.h"

int assert_fn(void *res, bool (*expect)(void *res), char *title, char *msg);
int assert_int(int res, int expect, char *title, char *msg);
int assert_str(char *res, char *expect, char *title, char *msg);

#endif