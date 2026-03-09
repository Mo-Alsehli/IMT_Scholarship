#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define COUNT 100

int main(int argc, char *argv[]) {
    if(argc != 2){
        printf("[ERROR] usage: \ncat filepath\n");
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);

    if(fd < 0){
        printf("[ERROR] can't open file: %s\n", argv[1]);
        return 1;
    }

    char buff[COUNT];
    int read_count = 0;

    while((read_count = read(fd, buff, COUNT)) > 0){
        write(1, buff, read_count);
    }

    close(fd);
    
    return 0;
}