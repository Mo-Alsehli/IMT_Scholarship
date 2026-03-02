#include <iostream>
#include <vector>
#include <array>


/*
** OOP [Object Oriented Programming]
*** Object is a concept represents and achieves multiple things.
**** Encapsulation: enacabsulate data and behaviour.
**** Inheritance.
**** Polymorphism.
*/


class CSerialInterface {
    public:
        virtual void send(u_int8_t* arr, int size) = 0;
        virtual int recv(u_int8_t* arr, int size) = 0;

        virtual void init() = 0;
};

class CUART : public CSerialInterface {
    public:
        CUART(){}

};


// Multi sensor system design
class CSensor {
    public:
        CSensor(int unit, double* readings): m_unit(unit), m_readings(readings){} 

        int set_serial_interface(CSerialInterface* interface){
            m_interface = interface;
        }

    private:
        int m_unit;
        double* m_readings;
        CSerialInterface* m_interface;

};

class CTempratureSensor:  public CSensor {
    public:
        CTempratureSensor(int unit): CSensor(unit, m_temp_readings.data()){}

    private:
        std::array<double, 10> m_temp_readings;
};


class CSerial {
    public:
    CSerial(int m_baudrate, int m_clock, int m_slave_address){}

    virtual void init(){}

    void send_data(char data){}

    void recieve_data(char& data){}


    protected:
        std::string m_slave_address;
        int m_clock;
        int m_baudrate;
        std::vector<char> data;
};


class CUART: public CSerial {

};


