#include<iostream>
#include "allocation.cpp"

//#include "static_keyword.cpp"


void swap(int& n1, int& n2){
    int temp = n1;
    n1 = n2;
    n2 = temp;
}


int main(){

    // int n1 = 100, n2 = 200;

    // std::cout << "Value before swapping: " << std::endl;
    // std::cout << "n1: " << n1 << " n2: " << n2 << std::endl;

    // swap(n1, n2);

    // std::cout << "Value After swapping: " << std::endl;
    // std::cout << "n1: " << n1 << " n2: " << n2 << std::endl;


    //test_method_chaining();


    //test_csensor_class();

    //test_cswap_main();

    test_allocation_main();

    return 0;
}