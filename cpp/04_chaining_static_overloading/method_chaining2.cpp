#include <iostream>

class CSwap {
    public:
        CSwap(int x, int y): m_x(x), m_y(y){}

        CSwap& swap(CSwap& other){
            int temp = this->m_x;
            this->m_x = other.m_x;
            other.m_x = temp;

            temp = this->m_y;
            this->m_y = other.m_y;
            other.m_y = temp;

            return (*this);
        }

        CSwap& print(){
            std::cout << "m_x: " << m_x << ", m_y: " << m_y << std::endl;

            return (*this);
        }

        CSwap& remove(){
            m_x = 0;
            m_y = 0;

            return (*this);
        }

    private:
        int m_x;
        int m_y;
};


void test_cswap_main(){
    CSwap sw1(20, 30), sw2(5, 10);

    sw1.swap(sw2).print().remove();
    std::cout << "After swap && remove " << std::endl;
    sw2.swap(sw1).print().remove();
}