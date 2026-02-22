#include <array>
#include <iostream>


/*
Arrays In Cpp
** Statically allocated memory

- There is an STL container for arrays in cpp beside the normal arrays.
- Arrays in cpp applys boundry checking
- Arrays can use iterators

- arr.empty() {For a cpp array type always returns false}
- arr.data() -> get pointer to underlying data
    - can be used to read and write but this is not recommended.
    - If you used it anyway so it's better to be read only.

*/



void test_arrays_main(){
    std::array<int, 10> my_arr;
    my_arr.fill(20);
    my_arr.at(3) = 50; // provide boundry checking.

    for(auto it = my_arr.begin(); it != my_arr.end(); ++it){
        std::cout << *it << std::endl;
    }

}