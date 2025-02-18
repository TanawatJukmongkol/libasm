#include <fcntl.h>
#include <errno.h>
#include <uchar.h>
#include "tests.h"

int tester_write()
{
    int     fd, size, res_size;
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
    fd = open("test_files/random_bytes", O_RDONLY);
    size = read(fd, rand_data, 1000);
    rand_data[size] = '\0';
    close(fd);

    fd = open("/tmp/random_bytes", O_RDWR | O_TRUNC);
    size = write(fd, rand_data, 1000);

    size = read(fd, expected, 1000);
    expected[size] = '\0';

    res_size = ft_write(fd, rand_data, 1000);
    assert_int (
        res_size, size,
        "random_bytes test", NULL
    );

    size = read(fd, expected, 1000);
    expected[size] = '\0';

    unlink("/tmp/random_bytes");
    close(fd);
    assert_str(result, expected, "random_bytes write result", "random bytes does not match");

    return 0;
}
