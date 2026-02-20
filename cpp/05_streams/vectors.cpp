#include <iostream>
#include <vector>


template <typename T>
class CMatrix {
    
    public:
    CMatrix(int rows, int cols): m_rows(rows), m_cols(cols){
        m_matrix.resize(m_rows, m_cols)
    }

    void input(){
        for(int i = 0; i < m_rows; i++){
            for(int j = 0; j < m_cols; j++){
                std::cin >> m_matrix[i][j];
            }
        }
    }

    CMatrix add(CMatrix other){
        CMatrix result(m_rows, m_cols);
        for(int i = 0; i < m_rows; i++){
            for(int j = 0; j < m_rows; j++){
                result[i][j] = m_matrix[i][j] + other[i][j];
            }
        }
    }

    CMatrix multiply(CMatrix other){
        CMatrix result(m_rows, m_cols);
        for(int i = 0; i < m_rows; i++){
            for(int j = 0; j < m_rows; j++){
                result[i][j] = m_matrix[i][j] * other[i][j];
            }
        }
    }


    CMatrix subtract(CMatrix other){
        CMatrix result(m_rows, m_cols);
        for(int i = 0; i < m_rows; i++){
            for(int j = 0; j < m_rows; j++){
                result[i][j] = m_matrix[i][j] - other[i][j];
            }
        }
    }

    void display(){
        for(int i = 0; i < m_rows; i++){
            for(int j = 0; j < m_rows; j++){
                std::cout << m_matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }


    private:
    std::vector<vector<T>> m_matrix;
    int m_rows, int m_cols;
};




void test_cmatrix(){

}