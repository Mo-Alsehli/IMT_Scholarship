#include <iostream>
#include <stack>
#include <sstream>


/*
*** STACKS
** stack is based on LIFO.
** stack<int> st;
** st.push(value); -> pushs an element
** st.pop(); -> removes the last element
** st.top(); -> returns the top element
** We can check if a number string is integer by using stoi within a try{} catch()
     as if it fails it throws an exception.

*/

/*
Assignment
Use stack to convert from infix notation to reverse polish notation and resolve 
a mathmatical expression as a command line argument.

*/


void test_stack(){
    std::stack<int> st;
}

// Parse polish notation

void polish_notation(){
    std::stack<int> st;
    std::string expression;

    std::cout << "Enter Polish expression: " << std::endl;
    std::getline(std::cin, expression);

    std::stringstream ss(expression);
    std::string token;
    while(ss >> token){
        if(token == "+" || token == "+" || token == "*" || token == "/"){
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();

            if(token == "+"){
                st.push(first + second);
            } else if(token == "*"){
                st.push(first * second);
            } else if(token == "-"){
                st.push(first - second);
            } else if(token == "/"){
                st.push(first / second);
            }
        } else {
            st.push(std::stoi(token));
        }
    }

    std::cout << "Result: " << st.top() << std::endl;

}