#include <iostream>
#include "stacks.cpp"
#include "queues.cpp"
#include "labs.cpp"
#include "labs2.cpp"


/*
** When dealing with matrices it's better to store them inside a 1d vector than 2d array.
    - Storing it that way leads to better performance from the context of cache.
    - We can access elements inside the matrix using this formula [(row*num_cols)+col]


*/


int main(int argc, char** argv){

    //polish_notation();
    //moving_average();
    //count_duplicate_words();

    // reverse_string("Test Reversed String");

    int n = 10;
    std::vector<int> range = {1, 2, 3, 5, 6, 7, 8, 9, 10};

    //get_missing_in_range(n, range);
    binary_format_queue(5);

    return 0;
}