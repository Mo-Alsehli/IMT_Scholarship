#include <iostream>



class Counter {
    private:
        int m_count = 0;
        int m_step = 1;

    public:
    int count(){
        return m_count;
    }

    Counter& count(int c){
        m_count += c;

        return (*this);
    }

    int step(){
        return m_step;
    }

    Counter& step(int s){
        m_step = s;

        return (*this);
    }

};


void test_method_chaining(){
    Counter c1;

    c1.count(10).step(2);

    std::cout << c1.count() << " | " << c1.step() << std::endl;
}