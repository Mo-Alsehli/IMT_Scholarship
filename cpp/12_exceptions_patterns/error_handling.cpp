#include <iostream>
#include <exception>
#include <cassert>
#include <type_traits> // For static_assert and meta-programming.s
#include <cerrno>
#include <cstdio>
#include <cstring>


/*
* Exceptions
** Assertion and Design by Contract
*** assert() is a macro.
*** it's a contract between developers for forcing specific design.
*** Syntax: assert(boolean expression && printf("error msg")).
*** assert is used only for debugging and it's removed in release.
*** There is a defined macro that is called NDEBUG which we pass to the compiler to activate the assert()
*** g++ -g -DNDEBUG main.cpp
*** Design by contract depends on three keys:
    - preconditions.
    - postconditions.
    - invariants.
*** static_assert() is used to make an assertion at compile time.
*** syntax: static_assert( bool-constexpr , unevaluated-string )

* Error Codes (errno)
*/


void test_assert(){
    assert(1 && printf("This is an assertion"));
    int i = 1;
    // static_assert(std::is_object<int>, "");
}

void check_file_exist(const char* filename){
    FILE* file = fopen(filename, "r");

    if(file == nullptr){
        printf("Error: %s\n", strerror(errno));
        printf("Error NO. %d\n", errno);
    } else {
        fclose(file);
    }
}