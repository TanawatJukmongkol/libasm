#include <fcntl.h>
#include <errno.h>
#include "tests.h"

int tester_read()
{
    char    expect[1000];
    char    result[1000];
    int     fd, size, res_size;

    printf("\n-- ft_read --\n");

    // Invalid FD
    assert_int (
        ft_read(-1, result, 1000), -1,
        "invalid fd test (< 0)", NULL
    );

    assert_int(errno, EBADF, "errno test 1", "expected EBADF");

    assert_int (
        ft_read(100, result, 1000), -1,
        "invalid fd test (DNE)", NULL
    );

    assert_int(errno, EBADF, "errno test 2", "expected EBADF");

    // Invalid directory
    fd = open("test_files", O_RDONLY);
    assert_int (
        ft_read(fd, result, 1000), -1,
        "invalid directory", NULL
    );
    assert_int(errno, EISDIR, "errno test invalid directory", "expected EISDIR");

    // example file
    fd = open("test_files/random_bytes", O_RDONLY);
    size = read(fd, expect, 1000);
    expect[size] = '\0';
    close(fd);

    // result file
    fd = open("test_files/random_bytes", O_RDONLY);
    res_size = ft_read(fd, result, 1000);
    result[res_size] = '\0';
    assert_int (
        res_size, size,
        "random_bytes test", NULL
    );
    close(fd);

    assert_str(result, expect, "random_bytes read result", "random bytes does not match");

    return 0;
}
