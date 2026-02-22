#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

/*
** Script for vector operations (from a file)
create 10 20 30
insert 5@2
erase 2   // remove element @ index 2
append 40
read 0 // should print the value at index 0
write 5@0 // modify index 0 to be 5.
show // prints vector
*/

class CVectorScript {
    public:
    CVectorScript(std::string script): m_script(script){};

    void parse_script(){
        std::ifstream input(m_script);
        std::string command;
        std::string token;

        while(std::getline(input, command)){
            std::stringstream ss(command);
            ss >> token;
            if(token == "create"){
                while(ss >> token)
                    m_data.push_back(std::stoi(token));
                    m_data_size = m_data.size();

                    std::cout << "[INFO] Creation Successfull \n";
            }else if(token == "insert"){
                ss >> token;
                int value = std::stoi(token);
                int index = std::stoi(token.substr(token.find('@')+1));

                m_data.insert(m_data.begin() + index, value);
                m_data_size = m_data.size();

                std::cout << "[INFO] Inserted " << value << "@" << index << std::endl;
            }else if(token == "erase"){
                ss >> token;
                int pos = std::stoi(token);
                if(pos >= m_data_size)
                    std::cerr << "[ERROR] Can't erase v[" << pos << "] Position Out of Boundry" << std::endl;
                else {
                    m_data.erase(m_data.begin()+pos);
                    m_data_size = m_data.size();
                    std::cout << "[INFO] Erased Value @" << pos << std::endl;
                }
            }else if(token == "append"){
                ss >> token;
                int value = std::stoi(token);
                m_data.push_back(value);
                m_data_size = m_data.size();

                std::cout << "[INFO] Appended " << value << std::endl;
            }else if(token == "read"){
                ss >> token;
                int pos = std::stoi(token);
                if(pos >= m_data_size)
                    std::cerr << "[ERROR] Can't read v[" << pos << "] Position Out of Boundry" << std::endl;
                else 
                    std::cout << "v[" << pos << "] = " << m_data[pos] << std::endl;
            }else if(token == "write"){
                ss >> token;
                int value = std::stoi(token);
                int index = std::stoi(token.substr(token.find('@')+1));

                if(index >= m_data_size)
                    std::cerr << "[ERROR] Can't modify v[" << index << "] Position Out of Boundry" << std::endl;
                else{
                    m_data[index] = value;
                    std::cout << "[INFO] writen " << value << "@" << index << std::endl;
                }
            }else if(token == "show"){
                for(int i = 0; i < m_data_size; i++){
                    std::cout << "v[" << i << "] = " << m_data[i] << std::endl;
                }
            }
        }
    }

    private:
        std::vector<int> m_data;
        std::string m_script;
        int m_data_size;
};


void test_vector_script(){
    CVectorScript vs("vector_script.txt");
    vs.parse_script();
}