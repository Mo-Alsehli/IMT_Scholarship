#include <iostream>
#include <cstring>

class CDevice {
    private:
        int m_id;
        char* m_name;

    public:
        CDevice(int id, const char* name){
            int len = strlen(name);
            m_name = new char[len+1];
            
            m_id = id;
            std::strcpy(m_name, name);
        }

        void print_data(){
            std::cout << "Name: " << m_name << " ,ID: " << m_id << std::endl;
        }

        ~CDevice(){
            delete[] m_name;
        }
};


void test_allocation_main(){
    const char* name = "Heat Sensor";
    CDevice d1(5, name);

    d1.print_data();
}