#include <iostream>


int parse_expression(std::string& exp){
    char op;
    int a = 0, b = 0;
    int result = 0;

    //std::cin >> exp;

    for(int i = 0; i < exp.size(); i++){
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            a = std::stoi(exp.substr(0, i));
            b = std::stoi(exp.substr(i+1));
            op = exp[i];
            break;
        }
    }

    switch (op)
    {
    case '+':
        result = a + b;
        break;
    
    case '-':
        result = a - b;
        break;
    
    case '/':
        result = a / b;
        break;
    
    case '*':
        result = a * b;
        break;
    default:
        std::cerr << "[ERROR] unknown operation\n";
        return -1;
    }

    return result;
}

void read_lines(){
    std::string line;

    while(std::getline(std::cin, line)){
        std::cout << line << std::endl;
    }

}

void parse_file_expressions(){

    std::string line;

    while(std::getline(std::cin, line)){
        std::cout << parse_expression(line) << std::endl;
    }

}

