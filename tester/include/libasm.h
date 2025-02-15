#ifndef	LIBASM_H
# define LIBASM_H

#include <stdlib.h>
#include <errno.h>

extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern ssize_t	ft_read(int fd, void *buf, size_t count);
extern size_t	ft_strlen(const char *s);
extern int		ft_strcmp(const char *s1, const char *s2);

#endif
