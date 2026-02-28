#include <iostream>
#include <any>
#include <typeinfo>
#include <vector>
#include <variant>
#include <fstream>


/**
 * Generic Type Handling
 ** Being generic can be at compile time or at runtime.
 ** We can be generic at runtime in C programming using the (void *) void pointer.
 ** (void *) is incomplete type that can be complete using casting at runtime.
 ** the (void*) implementation is very complicated and unsafe.
 ** cpp introduced <any> which is an abstraction for the (void*).
 ** unlike 'auto', 'any' is resolved at runtime not compile time.
 ** reading the data of any data type is using the any_cast<data_type>.
 ** 
 */


 template<typename T>
 T get_data(std::any x){
    T d;
    if(x.type() == typeid(T)){
        std::cout << "Any Data = " << std::any_cast<T>(x) << std::endl;
        d = std::any_cast<T>(x);
        return d;
    }

    return d;
 }

 void test_generic() {
    std::any x = 10;

    std::cout << "Value of any x: " << std::any_cast<int>(x) << std::endl;
    
    x = 3.14;
    
    std::cout << "Value of any x: " << std::any_cast<double>(x) << std::endl;

    // Checking for type
    std::cout << "Current type: " << x.type().name() << std::endl;
    
    if(x.type() == typeid(double)){
        std::cout << "any double: " << std::any_cast<double>(x) << std::endl;
    }

    double dd = get_data<double>(x);

    x = std::string("mohamed");

    std::string str = get_data<std::string>(x);

}


void test_vector_any(){
    std::vector<std::any> v_any;
    int ii = 10;
    double dd = 15.5;
    std::string str = "mohamed";
    bool bb = true;


    v_any.push_back(ii);
    v_any.push_back(dd);
    v_any.push_back(str);
    v_any.push_back(bb);

    get_data<int>(ii);
}

struct SPoint2D {
    int p1;
    int p2;
};

struct SPoint3D {
    int p1;
    int p2;
    int p3;
};

struct SPointVisitor {
    SPoint2D operator()(SPoint2D point){
        std::cout << "(" << point.p1 << ", " << point.p2 << std::endl;

        return point;
    }
};




void test_variant(){
    std::variant<int, float, std::string> var;

    var = 10;

    std::cout << "has int ? " << (std::holds_alternative<int>(var) ? "true" : "false") << std::endl;
    
    var = "mohamed";
    std::cout << "has int ? " << (std::holds_alternative<int>(var) ? "true" : "false") << std::endl;
    std::cout << "has string ? " << (std::holds_alternative<std::string>(var) ? "true" : "false") << std::endl;

    if(std::holds_alternative<std::string>(var)){
        std::cout << "The string in variant is: " << std::get<std::string>(var) << std::endl;
    }


}


void parse_file_with_variant(){
    std::ifstream in("data.txt");
    std::variant<int, double, std::string> var;
    
    if(!in.is_open()){
        std::cerr << "File not opened" << std::endl;
        return;
    }

    std::string line;
    

}