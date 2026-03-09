#include <iostream>
#include <unistd.h>


int main() {
    char* buf;
    size_t size = 100;
    std::cout << getcwd(buf, size) << std::endl;

    return 0;
}