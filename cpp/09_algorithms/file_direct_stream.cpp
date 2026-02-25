#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>



class CFileStream {
    public:
        CFileStream(std::string output, std::string input): m_output(output), m_input(input){}

        void copy_reverse_data(){
            if(!m_input.is_open() || !m_output.is_open()){
                std::cerr << "[ERROR] Faild to open the file..." << std::endl;
                return;
            }

            std::string line;
            std::getline(m_input, line);
            m_input.seekg(line.size());
            m_output << line;
            
            while(std::getline(m_input, line)){
                int line_len = line.size();
                m_output << line ;
               m_output.seekp((-1*(line_len+1)));
               m_output << std::endl;
            }
        }

    private:
    std::ofstream m_output;
    std::ifstream m_input;
};


void test_file_stream(){
    CFileStream fs("sensors_data_reversed.csv", "sensors_data.csv");

    fs.copy_reverse_data();
}