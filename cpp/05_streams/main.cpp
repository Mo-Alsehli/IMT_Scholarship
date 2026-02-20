#include <iostream>
#include "io_redirection.cpp"
#include "stringstream_uart.cpp"


int main(int argc, char* argv[]){
    // std::string exp;
    // std::cin >> exp;
    // std::cout << parse_expression(exp) << std::endl;

    /*
    // std::getline() with delimeter
    // NOTE: The default delimeter for cin is 'space' while for getline is newline '\n'

    std::string input;
    std::getline(std::cin, input, '+');
    int a = stoi(input);
    std::getline(std::cin, input);
    int b = stoi(input);

    int sum = a + b;

    std::cout << sum << std::endl;
    */

    // Read line by line

    // std::string line;
    // int i = 0;
    // while(std::cin >> line){
    //     std::cout << line << std::endl;
    // }

    // Read file by getline
    //read_lines();

    // parse arithmatic expressions
    //parse_file_expressions();

    //test_cuart_config();

    // Application Arguments (argc, ** argv)

    // for(int i = 0; i < argc; i++){
    //     std::cout << argv[i] << std::endl;
    // }
    // convert c-string to cpp string
    // std::string args(argv[0])

    test_cuart_config(argc, argv);


    return 0;
}