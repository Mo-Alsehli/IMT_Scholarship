#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <numeric> // for accumulate


bool is_alphabetical(std::string str){
    for(char c: str){
        if(!std::isalpha(c)){
            return false;
        }
    }

    return true;
}

void correct_path() {
    std::vector<std::string> paths = {
        "/home//root//docs",
        "/./lectures",
        "lab1/solution/.."
    };

    for (const auto& path : paths) {
        std::stringstream ss(path);
        std::string token;
        std::vector<std::string> stack;

        while (std::getline(ss, token, '/')) {

            if (token.empty() || token == ".")
                continue;

            if (token == "..") {
                if (!stack.empty())
                    stack.pop_back();
            } else {
                stack.push_back(token);
            }
        }

        std::string normalized;
        for (auto dir : stack) {
            normalized += "/" + dir;
        }

        if (normalized.empty())
            normalized = "/";

        std::cout << normalized << std::endl;
    }
}

/*
** vector
print using for_each()
even numbers using count_if()
sorting
using lambda
*/

void test_algorithms(){
    std::vector<int> v {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // printing
    std::for_each(v.begin(), v.end(), [](int num){std::cout << num << " ";});
    std::cout << std::endl;
    
    int even_count = std::count_if(v.begin(), v.end(), [](int num) {return (num % 2) == 0;});
    
    sort(v.begin(), v.end(), [](int a, int b) {return a < b;});
    std::cout << "After sorting" << std::endl;
    std::for_each(v.begin(), v.end(), [](int num){std::cout << num << " ";});
    
    std::cout << std::endl;
}


void test_algorithms2() {
    std::vector<int> v {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    auto it = std::find_if(v.begin(), v.end(), [](int num) {return (num % 2) == 0;});

    std::cout << "The first even num is: " << *it << std::endl;

    std::vector<int> v10;

    std::transform(v.begin(), v.end(), std::back_inserter(v10), [](int num) {return (num * 10);});

    std::cout << "After Multipling by 10: " << std::endl;
    std::for_each(v10.begin(), v10.end(), [](int num){std::cout << num << " ";});
    std::cout << std::endl;

    v.erase(std::remove_if(v.begin(), v.end(), [](int num) {return num % 2 != 0;}));

    std::cout << "After Removing odds: " << std::endl;
    std::for_each(v.begin(), v.end(), [](int num){std::cout << num << " ";});
}


void lambda_capturing(){
}






