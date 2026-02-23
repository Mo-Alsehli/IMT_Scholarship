#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <queue>
#include <stack>


/*
* LAB 1
* Count the maximum count of a duplicate in a string
*/
void count_duplicate_words(){
    std::string input = "mohamed magdi linux mohamed cpp yocto mohamed";
    std::stringstream ss(input);
    std::string token;
    std::map<std::string, int> count_map;
    int max_count = 0;

    while(ss >> token){
        count_map[token]++;
        max_count = (count_map[token] > max_count) ? count_map[token] : max_count;
    }


    std::cout<< "The max count is: " << max_count << std::endl;
}


void reverse_queue_stack(){
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    std::stack<int> st;

    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
}