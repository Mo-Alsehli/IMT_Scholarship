#include <iostream>
#include <vector>


template <typename T>
class CMatrix {
    
    public:
    CMatrix(int rows, int cols): m_rows(rows), m_cols(cols), m_matrix(rows, std::vector<T>(cols)) {
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
            for(int j = 0; j < m_cols; j++){
                result.m_matrix[i][j] = m_matrix[i][j] + other.m_matrix[i][j];
            }
        }
        return result;
    }

    CMatrix multiply(CMatrix other){
        CMatrix result(m_rows, m_cols);
        for(int i = 0; i < m_rows; i++){
            for(int j = 0; j < m_cols; j++){
                result.m_matrix[i][j] = m_matrix[i][j] * other.m_matrix[i][j];
            }
        }
        return result;
    }


    CMatrix subtract(CMatrix other){
        CMatrix result(m_rows, m_cols);
        for(int i = 0; i < m_rows; i++){
            for(int j = 0; j < m_cols; j++){
                result.m_matrix[i][j] = m_matrix[i][j] - other.m_matrix[i][j];
            }
        }
        return result;
    }

    void display(){
        for(int i = 0; i < m_rows; i++){
            for(int j = 0; j < m_cols; j++){
                std::cout << m_matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }


    private:
    std::vector<std::vector<T>> m_matrix;
    int m_rows;
     int m_cols;
};




void test_cmatrix(){
    CMatrix<int> mat1(2, 2);
    CMatrix<int> mat2(2, 2);

    std::cout << "Enter the first matrix: " << std::endl;
    mat1.input();

    std::cout << "Enter the second matrix: " << std::endl;
    mat2.input();

    std::cout << "The sum of the two matrices is: " << std::endl;
    CMatrix<int> sum = mat1.add(mat2);
    sum.display();

    std::cout << "The product of the two matrices is: " << std::endl;
    CMatrix<int> product = mat1.multiply(mat2);
    product.display();

    std::cout << "The difference of the two matrices is: " << std::endl;
    CMatrix<int> difference = mat1.subtract(mat2);
    difference.display();
}