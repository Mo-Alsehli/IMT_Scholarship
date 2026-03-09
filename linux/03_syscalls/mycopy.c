#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define COUNT 100

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("[ERROR] usage:\n mycopy input_file output_file\n");
        return 1;
    }

    int input = open(argv[1], O_RDONLY);
    if(input < 0){
        printf("[ERROR] can't open input file\n");
        return 1;
    }
    
    int output = open(argv[2], O_WRONLY | O_CREAT | O_APPEND, 0644);
    if(output < 0){
        printf("[ERROR] can't open output file\n");
        return 1;
    }

    char buff[COUNT];
    int read_count = 0;

    while((read_count=read(input, buff, COUNT)) > 0){
        if(write(output, buff, read_count) == -1){
            //printf("[ERROR] writing to output file\n");
            perror("open output");
            return 1;
        }
    }

    close(input);
    close(output);

    return 0;
}