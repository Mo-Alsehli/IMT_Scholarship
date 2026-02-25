#include <iostream>
#include <tuple>



/*
** pair vs tuple
** Pair is a standalone data type std::pair<T,T>.
    - Pair base is a template struct not a template class
    ```
    template <typename T1, T2>
    struct pair {
        T1 first;
        T2 second;
    }
    ```
** tuple has a variadic number of arguments of different data types.
    - inside #include <tuple>
    - std::tuple<string,int,float,....>
    - tuple also is based on struct and templates internally.
    - we can retrieve a datatype value using std::get<T>(tuple) or using std::get<index>(tuple)
    - tuples are used instead of very simple structs when we need the tuple unpacking syntax.

    - we can used the std::get<index> = value as an lvalue to change the value for a specific element.
    - But NOTE we can't using the std::get<i> inside a loop to retrieve the tuple elements.
    - Any value inside a template needs to be well known at compile time.
*/

void test_tuple_main(){
    std::tuple<std::string, int, float> t = std::make_tuple("mohamed", 25, 50.5);

    auto name = std::get<0>(t);
    auto age = std::get<1>(t);
    auto length = std::get<float>(t); // Note: if there are multiple data types with the same name we can't 
                                     //     get the value using this way.

    // Setting an element using get.

    std::get<0>(t) = "magdi";

    name = std::get<0>(t);

    std::cout << "Name: " << name << " Age: " << age << " Length: " << length << std::endl;
    
    
    // Unpacking syntax [Structure Binding].
    auto [name2, age2, langth2] = t;

    std::cout << "Name: " << name << " Age: " << age << " Length: " << length << std::endl;
}







