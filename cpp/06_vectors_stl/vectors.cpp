#include <iostream>
#include <vector>
#include <string>
#include <fstream>

/*
** Dynamically allocated memory
** Vector elements are contigous.
** Vectors bitfails:
    - random accessing vector for unallocated memory leads to an exception.
        -> v.at(out_index) = value;
        -> v[out_index] = value;
** We can return a pointer to the data inside the vector using the .data() method.
    - But note that returning that and using it might leed to a dangling pointer.
    - Because vector is dynamically allocated and can be extended at runtime so the pointer 
        pointing to the data might be changed and reserving an old state of it leeds to undefined behaviour.

** v.size() -> The actual size that can be accessed.
** v.capacity() -> The size allocated in the memory for the vector.

** free running functions std::begin(stl_container), std::end(stl_container).
    - Those functions can be used to return the iterator for the container even if for the c-style array.
*/




void test_vectors_main(){
    std::vector<int> v;

    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);

    int last = v.back(); // retrieves the last element
    v.pop_back(); // pops the last element.
}


void test_cmdline_sum_vectors(int argc, char** argv){
    std::vector<int> v(argc);

    for(int i = 1; i < argc; i++){
        v[i] = std::stoi(argv[i]);
    }
    int sum = 0;

    // Consider using accumulate insidethe the <algorithm>
    for(int n: v){
        sum += n;
    }
    std::cout << "Sum from cmd: " << sum << std::endl;
}

void test_cmdline_range(int argc, char** argv){
    std::string start_line(argv[1]);
    std::string end_line(argv[2]);

    std::vector<int> v;
    int equal_pos = start_line.find('=');
    int start = std::stoi(start_line.substr(equal_pos+1));
    equal_pos = end_line.find('=');
    int end = std::stoi(end_line.substr(equal_pos+1));

    for(int i = start; i <= end; i++){
        v.push_back(i);
    }

    int sum = 0;
    for(int num: v){
        sum += num;
    }

    std::cout << "The Sum from " << start << " To " << end << " is " << sum << std::endl;

}


void test_reverse_with_address(){
    std::vector v {1, 2, 3, 4, 5, 6};

    auto it = v.rbegin();

    std::cout << "v.rbegin()-> " << &(*v.rbegin()) << std::endl;
    std::cout << "v.rend()-> " << &(*v.end()) << std::endl;

    std::cout << "v.begin()-> " << std::addressof(*v.begin()) << std::endl;
    std::cout << "v.end()-> " << std::addressof(*v.end()) << std::endl;

    for(; it != v.rend(); it++){
        std::cout << *it << " " << &it << std::endl;

    }
}


void test_size_capacity_vector(){
    std::ofstream out("csv_factor.csv");
    std::vector<int> v;

    out << "size,capacity" << '\n';

    for(int i = 0; i < 100; i++){
        for(int i = 0; i < 50; i++){
            out << v.size() << "," << v.capacity()<< '\n';
            v.push_back(i);
        }
    }
}