#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define SIZE 1024
#define PAGE_COUNT 20

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("[ERROR] usage less path/to/file \n");
        return 1;
    }

    char* buff[SIZE];

    int fd = open(argv[1], O_RDONLY);
    int line_count = 0;

    size_t read_bytes = 0; 

    char space;
    
    while(read_bytes = read(fd, buff, SIZE)){
        for(int i = 0; i < read_bytes; i++){
            write(STDOUT_FILENO, &buff[i], 1);

            if(&buff[i] == '/n'){
                line_count++;
            }

            if(line_count == PAGE_COUNT){
                printf(":");
                printf("\r        \r");
                line_count = 0;
            }
        }
        
    }

    return 0;
}