#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> // for accumulate
#include <sstream>
#include <iterator>


/*
** Algorithms
** Stop using for loops and use function algorithms instead of it.
** Common Algorithms Operations
*** accumulate (accumalate(begin(), end(), compare function))
    - It takes the iterator begin and end and can take a comparing funtion that takes input of
        the same objects and return a reference to it.
    - It accumulate(converts) a container into one object.
    - Like getting the sum of multiple numbers inside a containter (accumlating numbers).
    - Can be used with strings.

*** reverse (reverse(begin, end))
    - Reverses a container based on its iterators.
*** copy (copy(src_begin, src_end, dist_begin)
         copy_if(src_begin, src_end, dist_begin, predicate)
         copy_in(src_begin, num_to_copy, dist_begin)
    - copy_if takes the predicate which is a function that returns boolean and make comparison.
    - copy_in takes the number of elements to be copied to the distination.
    - NOTE: copy doesn't make allocation so the distination needs to have enough space to accept from source.
    - We need to use back_inserter(dist.begin()) so that if there is no space it pushs back.
*** sort
*** transform
*** for-each (for_each(begin, end, cmp))
    - makes a loop from begin to end and make the operation in-place.
*** transform (transform(begin, end, distination.begin, cmp))
    - makes a loop from begin to end and make the operation on distination.
*** generate

** Lambda Function (Expression) && Callable object: #inlcude <functional>
*** Callable object is an abstraction of a function pointer.
*** int (*fp)(int a, int b, ..) -> syntax for function to pointer int C.
*** There is a type called standard function in cpp that memics the functions pointer in C.
    - std::function<return_type(args)> name;
*** Function Object (Functor)
    - It's an operator overloading for call operator '()'
    - The definition of it is as following: operator()(args){}
*** std::invoke() -> It's used to call any type of callable.
*/


/*
** Assignment
*** We have a file containing data.
*** We need to put this file in another file but with lines reversed.
*** We reverse the lines in the bottom to be the top lines.
*** Idea for it:
    - We need to make direct streaming.
    - The two operations needed are seek() then reverse().
*/


std::string join(std::string acc, std::string next){
    return (acc + ',' + next);
}


void test_accumulate(){
    std::vector<std::string> csv_line = {"Name", "Age", "Length"};

    // Join CSV header using accumalate.

    std::string joined = accumulate(csv_line.begin()+1, csv_line.end(), csv_line[0], join);

    std::cout << joined << std::endl;
}


void test_reverse(){
    std::vector<std::string> string_v;
    std::string str;

    std::getline(std::cin, str);

    std::stringstream ss(str);
    std::string token;

    while(ss >> token){
        string_v.push_back(token);
    }

    std::reverse(string_v.begin(), string_v.end());

    for(std::string word: string_v){
        std::cout << word << " " << std::endl;
    }
}

void test_copy(){

    std::string name = "mohamed magdi";
    std::string copy_name;

    std::copy(name.begin(), name.end(), std::back_inserter(copy_name));

    std::cout << copy_name << std::endl;

    std::vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> evens;

    std::copy_if(nums.begin(), nums.end(), std::back_inserter(evens), [&](int a){ return (a % 2) == 0;});

    // for_each()
    std::for_each(evens.begin(), evens.end(), [](int a) {std::cout << a << std::endl;});
    
    std::vector<int> transformed;
    
    std::transform(nums.begin(), nums.end(), std::back_inserter(transformed), [](int a){return a * 10;});
    std::for_each(transformed.begin(), transformed.end(), [](int a) {std::cout << a << ' ';});

    std::cout << std::endl;

}

// Practice about Function Objects.
class CNumChecker {   
    public:

        enum {CHECK_EVEN, CHECK_ODD, CHECK_PRIME};

        bool operator()(int check, int num){
            switch (check)
            {
            case CHECK_EVEN:
                return isEven(num);
                break;
            case CHECK_ODD:
                return isOdd(num);
                break;
            case CHECK_PRIME:
                return isPrime(num);
                break;
            
            default:
                return false;
            }
        }


    private:
        bool isEven(int n) {return n % 2 == 0;}
        bool isOdd(int n) {return n % 2 != 0;}
        bool isPrime(int n) {return false;}
};


void test_num_checker(){


    CNumChecker checker;
    // Calling an object as a function (callable object)
    std::cout << checker(CNumChecker::CHECK_EVEN, 24) << std::endl;
}


