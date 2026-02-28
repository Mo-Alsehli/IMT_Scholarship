#include <iostream>
#include <memory> // for smart pointers
#include <utility>


/**
 * Problems with C Raw pointers
 ** Ownership in raw pointers doesn't exist.
 * unique_ptr in cpp
 ** It acts as the single owener of the object pointer.
 *** unique_ptr<T> ptr;
 *** ptr = make_unique<T>(&var);
 ** Can be used like ordinary pointer: *ptr = val;
 ** unique_ptr makes the object not copyable.
 *** unique_ptr.get() returns the raw pointer for the data.
 *** mover the ownership unique_ptr2 = std::move(unique_ptr1);

 */
 

class CUARTConfig {
    public:
    CUARTConfig(int baudrate, int parity, std::string address, int stopbit):
    m_baudrate(baudrate),
    m_parity(parity),
    m_address(address),
    m_stopbit(stopbit){}

    void display(){
        std::cout << "Baudrate: " << m_baudrate << " parity: " << m_parity << " Address: " << m_address << std::endl;
    }


    private:
        int m_baudrate;
        int m_parity;
        std::string m_address;
        int m_stopbit;
};


void test_unique_ptr(){
    std::unique_ptr<int> ptr = std::make_unique<int>(20);
    
    std::cout << *ptr << std::endl;

    std::cout << ptr.get() << std::endl;
}