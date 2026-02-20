#include <iostream>
#include <fstream>
#include <string>


class CSerializable {
    public:
        CSerializable(int id, std::string name): m_id(id), m_name(name){};

        void display(){
            std::cout << "Serializable Data=> [" << m_id << "] [" << m_name << "]\n";
        }

        CSerializable& serialize(std::string out_filename){
            std::ofstream out(out_filename, std::ios::binary);

            if(!out.is_open()){
                std::cerr << "[ERROR] Faild to open: " << out_filename << std::endl;
                std::cerr << "[ERROR] serialization Faild" << std::endl;

                return (*this);
            }

            out.write(reinterpret_cast<const char*> (this), sizeof(*this));
            out.close();

            return *this;
        }

        CSerializable& deserialize(std::string in_filename, CSerializable* other){
            std::ifstream in(in_filename, std::ios::binary);

            if(!in.is_open()){
                std::cerr << "[ERROR] Faild to open: " << in_filename << std::endl;
                std::cerr << "[ERROR] Deserialization Faild" << std::endl;
                return (*this);
            }

            in.read(reinterpret_cast<char*> (other), sizeof(*other));
            in.close();

            return (*this);
        }


    private:
        std::string m_name;
        int m_id;
};


void test_serializable_main(){
    CSerializable s1(1, "Magdi");
    CSerializable* s2 = new CSerializable(0, "");

    s1.serialize("serialize.bin").deserialize("serialize.bin", s2);
    s2->display();
}