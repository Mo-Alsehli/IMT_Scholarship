#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <fstream>



class CUartConfig {
    public:
    void load_configurations(){
        std::string line;

        while(std::getline(std::cin, line)){
            std::stringstream ss(line);
            std::string key;
            std::string value;
            std::getline(ss, key, '=');
            std::getline(ss, value);
            confs.push_back(std::make_pair(key, value));
        }
    }

    void show(){
        for(auto pair: confs){
            std::cout << pair.first << "=" << pair.second << std::endl;
        }
    }

    void load_argv_conf(int argc, char* argv[]){
        for(int i = 1; i < argc; i++){
            std::string line(argv[i]);
            std::stringstream ss(line);
            std::string key;
            std::getline(ss, key, '=');

            // if(key == "baudrate"){
            //     ss >> m_baudrate;
            // }else if(key == "parity"){
            //     ss >> m_parity;
            // }else if(key == "slaveaddress"){
            //     ss >> m_slave_address;
            // }else if(key == "stopbit"){
            //     ss >> m_parity;
            // }

            if(key == "in"){
                ss >> input;
            }else if(key == "out"){
                ss >> output;
            }else {
                std::cerr << "unkown argument" << std::endl;
            }
        }

        //std::cout << "baudrate: " << m_baudrate << std::endl;
    }

    void load_from_file() {
    std::ifstream input_file(input);
    std::ofstream output_file(output);

    if (!input_file) {
        std::cerr << "Failed to open input file\n";
        return;
    }

    std::string line;

    while (std::getline(input_file, line)) {
        std::stringstream ss(line);
        std::string key, value;

        std::getline(ss, key, '=');

            if (key == "baudrate") {
                ss >> m_baudrate;
            } else if (key == "parity") {
                ss >> m_parity;
            } else if (key == "slaveaddress") {
                ss >> m_slave_address;
            } else if (key == "stopbit") {
                ss >> m_stopbits;
            }
    }

    output_file << "baudrate=" << m_baudrate << '\n';
    output_file << "parity=" << m_parity << '\n';
    output_file << "slaveaddress=" << m_slave_address << '\n';
    output_file << "stopbit=" << m_stopbits << '\n';
}



    private:
        int m_baudrate;
        std::string m_parity;
        int m_stopbits;
        int m_slave_address;
        std::string input;
         std::string output;

        std::vector<std::pair<std::string, std::string>> confs;
};


void test_cuart_config(int argc, char* argv[]){
    CUartConfig cfg;
    cfg.load_argv_conf(argc, argv);
    cfg.load_from_file();
}