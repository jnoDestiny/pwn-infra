#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>

int main() {
    void *page = mmap((void *)0x1337000,
                      0x1000,
                      PROT_READ | PROT_WRITE | PROT_EXEC,
                      MAP_PRIVATE | MAP_ANON,
                      -1,
                      0);
    
    if (page == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }

    ssize_t bytesRead = read(0, page, 0x1000);
    if (bytesRead < 0) {
        perror("read failed");
        munmap(page, 0x1000);
        exit(EXIT_FAILURE);
    }

    ((void (*)())page)();

    munmap(page, 0x1000);

    return 0;
}

