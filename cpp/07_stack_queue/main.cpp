#include <iostream>
#include "stacks.cpp"
#include "queues.cpp"
#include "labs.cpp"


/*
** When dealing with matrices it's better to store them inside a 1d vector than 2d array.
    - Storing it that way leads to better performance from the context of cache.
    - We can access elements inside the matrix using this formula [(row*num_cols)+col]


*/


int main(int argc, char** argv){

    //polish_notation();
    //moving_average();
    count_duplicate_words();

    return 0;
}