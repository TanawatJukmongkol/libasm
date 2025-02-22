#include <fcntl.h>
#include <errno.h>
#include <uchar.h>
#include "tests.h"

int tester_write()
{
    int     fds[2], fds_test[2], test_file, size, res_size;
    char    rand_data[1000];
    char    expected[1000], result[1000];

    printf("\n-- ft_write --\n");

    // Invalid FD
    assert_int (
        ft_write(-1, "Hello, world!", 1000), -1,
        "invalid fd test (< 0)", NULL
    );

    assert_int(errno, EBADF, "errno test 1", "expected EBADF");

    close(42);
    assert_int (
        ft_write(42, "Hello, world!", 1000), -1,
        "invalid fd test (DNE)", NULL
    );

    assert_int(errno, EBADF, "errno test 2", "expected EBADF");

    assert_int (
        ft_write(100, NULL, 1000), -1,
        "invalid buffer test (NULL)", NULL
    );
    assert_int( errno, EINVAL, "errno test 3", "expected EINVAL");

    // example file
    test_file = open("test_files/random_bytes", O_RDONLY);
    if (read(test_file, rand_data, 1000) < 0)
        return 1;
    close(test_file);

    if (pipe(fds) < 0)
        return 1;
    size = write(fds[1], rand_data, 1000);
    result[size] = '\0';
    close(fds[1]);
    if (read(fds[0], expected, 1000) < 0)
        return 1;
    close(fds[0]);

    if (pipe(fds_test) < 0)
        return 1;
    res_size = ft_write(fds[1], rand_data, 1000);
    result[res_size] = '\0';
    close(fds_test[1]);
    if (read(fds_test[0], result, 1000) < 0)
        return 1;
    close(fds_test[0]);

    assert_int (
        res_size, size,
        "random_bytes test size", NULL
    );

    assert_str(result, expected, "random_bytes write result", "random bytes does not match");

    return 0;
}
