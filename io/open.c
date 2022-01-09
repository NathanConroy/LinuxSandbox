#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST_FILE "hello.txt"

/*
 * Open a file. On error, print message and exit.
 */
int do_open() {
    int fd = open(TEST_FILE, O_RDWR);
    if (fd == -1) {
        printf("Error opening test file. Exiting ...\n");
        exit(1);
    }
    return fd;
}

/*
 * Close a file. On error, print message and exit.
 */
void do_close(int fd) {
    int stat = close(fd);
    if (stat == -1) {
        printf("Error closing test file. Exiting ...\n");
        exit(1);
    }
}

int
main(int argc, char *argv[]) {
    int fd = do_open();
    do_close(fd);
    return 0;
}
