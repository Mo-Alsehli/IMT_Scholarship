#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <queue>


void reverse_string(std::string str){
    std::stack<char> st;

    for(char c: str){
        st.push(c);
    }

    while(!st.empty()){
        std::cout << st.top();
        st.pop();
    }

    std::cout << std::endl;
}

void get_missing_in_range(int n, std::vector<int>& range){
    int valid_sum = 0;
    int curr_sum = 0;

    for(int num: range){
        curr_sum += num;
    }

    for(int i = 1; i <= n; i++){
        valid_sum += i;
    }

    std::cout << "Missing number is: " << valid_sum - curr_sum << std::endl;
}

void binary_format_queue(int n){
    std::queue<std::string> result;
    std::stack<char> bin_str_q;
    std::string bin_str = "0";
    
    for(int i = 1; i <= n; i++){
        int temp = i;
        while(temp){
            if(temp % 2){
                bin_str_q.push('1');
            }else {
                bin_str_q.push('0');
            }
            temp /= 2;
        }

        while(!bin_str_q.empty()){
            bin_str.push_back(bin_str_q.top());
            bin_str_q.pop();
        }

        std::cout << i << "in binary is: " << " 0b" << bin_str << std::endl;
        result.push(bin_str);
        bin_str.clear();
    }
}