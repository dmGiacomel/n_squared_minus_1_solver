#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <vector>

template <typename datatype>
class Matrix{
private:

    int rows;
    int columns;
    datatype **matrix;
    datatype** allocateMatrix(int rows, int columns);
    void freeMatrix(datatype **matrix);

public:

    //Copy Constructor
    Matrix(const Matrix& other);

    //Move constructor
    Matrix(Matrix&& other) noexcept;

    Matrix(int rows, int columns);
    Matrix(int rows, int columns, datatype initial_value);
    ~Matrix();
    int getRows();
    int getColumns();
    std::vector<datatype> getRowValues(int row);
    std::vector<datatype> getColumnValues(int column);
    datatype** getRawPointer();
    datatype getValueAt(int row, int column);
    void setValueAt(int row, int column, datatype value);

    void setValueToAllPositions(datatype data);
    void printMatrix();

    //move assignement operator
    Matrix<datatype>& operator=(Matrix&& other) noexcept;
    //copy assignement operator
    Matrix<datatype>& operator=(const Matrix& other);

};

//copy assignement operator
template <typename datatype>
Matrix<datatype>& Matrix<datatype>::operator=(const Matrix& other){

    if(this != &other){
        //free the current heap memory in order to empty the object first
        freeMatrix(matrix);
        rows = other.rows;
        columns = other.columns;

        matrix = allocateMatrix(rows, columns);
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                matrix[i][j] = other.matrix[i][j];
            }
        }
        
        //std::cout << "Matrix Copied!\n";
    }
    return *this;
}

//move assignement operator
template <typename datatype>
Matrix<datatype>& Matrix<datatype>::operator=(Matrix&& other) noexcept {
    if (this != &other) {
        freeMatrix(matrix);

        columns = other.columns;
        rows = other.rows;
        matrix = other.matrix;

        other.columns = 0;
        other.rows = 0;
        other.matrix = nullptr;

        //std::cout << "Matrix Moved!\n";
    }

    return *this;
}


//copy constructor
template <typename datatype>
Matrix<datatype>::Matrix(const Matrix& other)
    :rows(other.rows), columns(other.columns) {
    matrix = allocateMatrix(rows, columns);
    //memcpy(matrix[0], other.matrix[0], rows * columns * sizeof(datatype));
    //MALDITO padding

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            matrix[i][j] = other.matrix[i][j];
        }
    }

    //std::cout << "Matrix Copied!\n";

}


//move constructor
template <typename datatype>
Matrix<datatype>::Matrix(Matrix&& other) noexcept 
    :rows(other.rows), columns(other.columns), matrix(other.matrix){
    other.matrix = nullptr;
    other.rows = 0;
    other.columns = 0;

    //std::cout << "Matrix Moved!\n"; 
}



template<typename datatype>
datatype** Matrix<datatype>::allocateMatrix(int rows, int columns){
    
    datatype** matrix; 

    matrix = (datatype**)calloc(rows, sizeof(datatype*));
    matrix[0] = (datatype*)calloc(rows * columns, sizeof(datatype));

    for(int i = 1; i < rows; i++){
        matrix[i] = matrix[0] + i * columns;
    }

    return matrix;
}

template <typename datatype> 
Matrix<datatype>::Matrix(int rows, int columns)
    :rows(rows), columns(columns) {
    this->matrix = allocateMatrix(rows, columns);
    //std::cout << "Matrix Created!\n";
}

template <typename datatype> 
Matrix<datatype>::Matrix(int rows, int columns, datatype initial_value)
    :rows(rows), columns(columns) {

    this->matrix = allocateMatrix(rows, columns);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            matrix[i][j] = initial_value;
        }
    }

    //std::cout << "Matrix Created!\n";

}

template <typename datatype>
void Matrix<datatype>::freeMatrix(datatype** matrix){
    if (matrix != nullptr){
        free(matrix[0]);
        free(matrix);
    }
}

template <typename datatype>
Matrix<datatype>::~Matrix(){
    freeMatrix(matrix);
    //std::cout << "Matrix Deleted!\n";
}

template <typename datatype>
int Matrix<datatype>::getColumns(){
    return this->columns;
}

template <typename datatype>
int Matrix<datatype>::getRows(){
    return this->rows;
}

template <typename datatype>
datatype** Matrix<datatype>::getRawPointer(){
    return matrix;
}

template <typename datatype>
std::vector<datatype> Matrix<datatype>::getRowValues(int row){

    std::vector<datatype> row_values;
    for(int i = 0; i < columns; i++)
        row_values.push_back(matrix[row][i]);
    return row_values;
}

template <typename datatype>
std::vector<datatype> Matrix<datatype>::getColumnValues(int column){

    std::vector<datatype> column_values;
    for(int i = 0; i < rows; i++)
        column_values.push_back(matrix[i][column]);
    return column_values;
}

template <typename datatype>
datatype Matrix<datatype>::getValueAt(int row, int column){
    return matrix[row][column];
}

template <typename datatype>
void Matrix<datatype>::setValueAt(int row, int column, datatype data){
    matrix[row][column] = data;
}

template <typename datatype>
void Matrix<datatype>::setValueToAllPositions(datatype data){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            matrix[i][j] = data;
        }
    }
}

template <typename datatype>
void Matrix<datatype>::printMatrix(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}
#endif