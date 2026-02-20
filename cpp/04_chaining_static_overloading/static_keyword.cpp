#include <iostream>

class CSensor {
    public:
        CSensor(int reading) {
            m_sensors_count++;
            m_sensor_id = m_sensors_count;
            m_last_reading = reading;
        }

        ~CSensor() {
            m_sensors_count--;
        }

        static int sensors_count(){
            return m_sensors_count;
        }

        int last_reading(){
            return m_last_reading;
        }

    private:
        int m_sensor_id;
        int m_last_reading;
        static int m_sensors_count;
};

int CSensor::m_sensors_count = 0;


void test_csensor_class(){
    CSensor* s1 = new CSensor(20);
    CSensor s2(30), s3(40), s4(50);
    std::cout << "Current Number of Sensors: " << CSensor::sensors_count() << std::endl;

    std::cout << "s2 Last reading: " << s2.last_reading() << std::endl;

    delete s1;

    std::cout << "[After deletion] Current Number of Sensors: " << CSensor::sensors_count() << std::endl;

}