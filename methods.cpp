#include <iostream>
#include <fstream>
#include "Matrix.hpp"


double abs(double number){
    return (number > 0 ? number : -number);
}


int Matrix::number_of_matrices = 0;


Matrix::Matrix(){

    rows    = 0;
    cols    = 0;
    numbers = NULL;

}


Matrix::Matrix(int _rows, int _cols){
    
    rows    = _rows;
    cols    = _cols;
    numbers = new double*[rows];

    for (int row = 0; row < rows; row++)
        numbers[row] = new double[cols]{};

}


Matrix::~Matrix(){

    for (int row = 0; row < rows; row++)
        delete [] numbers[row];
    
    delete [] numbers;
    numbers = NULL;

}


void Matrix::getMatrix(){

    this -> ~Matrix();

    std::cin >> rows >> cols;
    numbers = new double*[rows];

    for (int row = 0; row < rows; row++){

        numbers[row] = new double[cols];

        for (int col = 0; col < cols; col++)
            std::cin >> numbers[row][col];
        
    }

}


void Matrix::getMatrix(const char* name_file){

    std::ifstream file;
    file.open(name_file);

    if (file.is_open()){
        
        std::string pass_string;

        for (int i = 0;  i < number_of_matrices; i++) getline(file, pass_string);
        if (file.eof())
        {
            std::cout << "file has no more matrices..." << std::endl;
            file.close();
            return;
        }


        this -> ~Matrix();
        file >> rows >> cols;
        numbers = new double*[rows];

        for (int row = 0; row < rows; row++){

            numbers[row] = new double[cols];

            for (int col = 0; col < cols; col++)
                file >> numbers[row][col];
            
        }

        number_of_matrices++;
    }
    else{
        std::cout << "file did not open..." << std::endl;
    }

    file.close();
}


void Matrix::printMatrix(){
    
    constexpr double EPSILON = 1e-5;

    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++){

            if (abs(numbers[row][col]) < EPSILON)
            {
                std::cout << 0 << " ";
                continue;
            }
            std::cout << numbers[row][col] << " ";

        }
        std::cout << "\n";
    }
}


void Matrix::printMatrix_in_file(const char* name_file){

    std::ofstream file;
    file.open(name_file);

    if (file.is_open()){

        constexpr double EPSILON = 1e-5;

        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (abs(numbers[row][col]) < EPSILON)
                {
                    file << 0 << " ";
                    continue;
                }
                file << numbers[row][col] << " ";
            }
            file << "\n";
        }
    }

    file.close();
}


Matrix& Matrix::operator=(const Matrix& m){

    this -> ~Matrix();
    rows = m.rows;
    cols = m.cols;
    
    numbers = new double*[rows];

    for (int row = 0; row < rows; row++){
        numbers[row] = new double[cols];
        for (int col = 0; col < cols; col++){
            numbers[row][col] = m.numbers[row][col];
        }
    }

    return *this;
}


Matrix Matrix::operator*(const Matrix& m){

    Matrix result(rows, m.cols);
    if(cols == m.rows){
        
        for (int row1 = 0; row1 < rows; row1++){
            for (int col2 = 0; col2 < m.cols; col2++){
                for (int col1 = 0; col1 < cols; col1++){

                    result.numbers[row1][col2] += numbers[row1][col1] * m.numbers[col1][col2];

                }
            }
        }

    }
    else {
        std::cout << "* is not possible..." << std::endl;
    }
    
    return result;

}


Matrix Matrix::operator*(const int number){

    Matrix result(rows, cols);

    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++){

            result.numbers[row][col] = numbers[row][col] * number;

        }
    }
    return result;
}


Matrix Matrix::operator-(const Matrix& m){

    Matrix result(rows, cols);

    if (cols == m.cols && rows == m.rows){
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){

                result.numbers[row][col] = numbers[row][col] - m.numbers[row][col];

            }
        }
    }
    else std::cout << "- is not possible..." << std::endl;

    return result;
}


Matrix Matrix::operator+(const Matrix& m){

    
    Matrix result(rows, cols);

    if (cols == m.cols && rows == m.rows){
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){

                result.numbers[row][col] = numbers[row][col] + m.numbers[row][col];

            }
        }
    }
    else std::cout << "+ is not possible..." << std::endl;
    
    return result;
}


bool Matrix::operator==(const Matrix& m){
    constexpr double EPSILON = 1e-5;
    bool equal = true;
    
    if (rows == m.rows && cols == m.cols){

        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){

                if (abs(numbers[row][col] - m.numbers[row][col]) > EPSILON) equal = false;

            }
        }

    }
    else equal = false;

    return equal;
}


bool Matrix::operator!=(const Matrix& m){
    constexpr double EPSILON = 1e-5;
    bool equal = true;

    if (rows == m.rows && cols == m.cols){

        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){

                if (abs(numbers[row][col] - m.numbers[row][col]) > EPSILON) equal = false;

            }
        }

    }
    else equal = false;

    return !equal;
}


bool Matrix::operator==(const int number){

    bool equal = true;

    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++){

            if ((row != col && numbers[row][col] != 0) || (row == col && numbers[row][col] != number)) equal = false;

        }
    }

    return equal;
}


void Matrix::Swap(int row1, int row2){

    if (row1 >= 0 && row1 <= rows && row2 >= 0 && row2 <= rows){

        for (int col = 0; col < cols; col++){

            double help_value = numbers[row1][col];
            numbers[row1][col] = numbers[row2][col];
            numbers[row2][col] = help_value;

        }
    }
    else
        std::cout << "Wrong values of rows in Swap..." << std::endl;
    
}


void Matrix::MultyRow(int row, double multy_value){

    if (row >= 0 && row <= rows){

        for (int col = 0; col < cols; col++)
            numbers[row][col] *= multy_value;
        
    }
    else
        std::cout << "Wrong value of row in MultyRow..." << std::endl;
    
}


void Matrix::MultyMergeRows(int row1, int row2, double multy_value){

    if (row1 >= 0 && row1 <= rows && row2 >= 0 && row2 <= rows){

        for (int col = 0; col < cols; col++){

            numbers[row1][col] += numbers[row2][col] * multy_value;

        }
    }
    else
        std::cout << "Wrong values of rows in Swap..." << std::endl;
    
}


bool Matrix::ZeroCol(int row, int col){

    bool all_zero = true;

    for (; row < rows; row++){
        if(numbers[row][col] != 0) all_zero = false;
    }

    return all_zero;
}


bool Matrix::AllZeroRow(int row){

    bool all_zero = true;
    if ((row < 0) || (row >= rows)) return false;

    for (int col = 0; col < cols; col++){
        if (numbers[row][col] != 0) all_zero = false;
    }

    return all_zero;
}


int Matrix::MinValueCol(int row, int col){

    int min = abs(numbers[row][col]), number_minrow = row;

    for (; row < rows; row++){
        if ((abs(numbers[row][col]) < min && abs(numbers[row][col]) != 0) || (min == 0 && abs(numbers[row][col]) != 0)){

            number_minrow = row;
            min = abs(numbers[row][col]);

        }
    }

    return number_minrow;
}


void Matrix::ZerosUnderMain(int row, int col){

    for (int current_row = row + 1; current_row < rows; current_row++){
        MultyMergeRows(current_row, row, 0 - (numbers[current_row][col]));
    }
}


void Matrix::ZerosUpperMain(int row, int col){

    for (int current_row = row - 1; current_row >= 0; current_row--){
        this -> MultyMergeRows(current_row, row, -(numbers[current_row][col]));
    }
}


bool Matrix::AllZeroCol(int col){
    bool flag = true;
    if ((col < 0) || (col >= cols)) return false;

    for (int row = 0; row < rows; row++){
        if (numbers[row][col]) flag = false;
    }

    return flag;
}


void Matrix::printAndCheckAnswer(Matrix& X, Matrix& A, Matrix& B){

    int row = rows - 1, col = 0, count_of_values = 1;
    bool flag = true;
    
    for (; AllZeroRow(row); row--);
    if (row < 0) {
        std::cout << "Answer is empty" << std::endl;
        return;
    }
    for (; col < cols - 1; col++){
        if(numbers[row][col]) flag = false;
    }
    if (flag){
        std::cout << "Answer is empty" << std::endl;
        return;
    }

    row = col = 0;
    std::cout << "Answer:" << std::endl;
    
    while(row < rows && col < cols){

        if(numbers[row][col]){

            for (int cur_col = col + 1; cur_col < cols; cur_col++){
                if (cur_col < cols - 1){
                    std::cout << -1 * numbers[row][cur_col] << " * x" << cur_col + 1 << " + ";
                }
                else {
                    std::cout << numbers[row][cur_col];
                    X.numbers[count_of_values - 1][0] = numbers[row][cur_col];
                }
            }
            std::cout << std::endl;

            row++, col++, count_of_values++;
        }
        else if (AllZeroCol(col)){
            std::cout << "--------------" << std::endl;
            row++, count_of_values++;
        }
        else{
            std::cout << "x" << count_of_values << std::endl;
            row++, count_of_values++;
        }
    }
    if (A*X == B) std::cout << "Answer is right!" << std::endl;
    else std::cout << "Answer is wrong!" << std::endl;
}


void Matrix::Gauss(){
    
    Matrix X(cols - 1, 1), A(rows, cols - 1), B(rows, 1);
    int current_row = 0, current_col = 0;

    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols - 1; col++){
            A.numbers[row][col] = numbers[row][col];
        }
    }
    for (int row = 0; row < rows; row++){
        B.numbers[row][0] = numbers[row][cols - 1];
    }

    while((current_col < cols) && (current_row < rows)){

        if(this -> ZeroCol(current_row, current_col)) current_col++;

        else{

            Swap(current_row, MinValueCol(current_row, current_col));
            MultyRow(current_row, 1 / numbers[current_row][current_col]);
            ZerosUnderMain(current_row, current_col);

            ++current_row;
            ++current_col;
        }
    }


    current_row = rows - 1;
    current_col = 0;
    
    while (current_row >= 0 && AllZeroRow(current_row)) current_row--;
    if (current_row >= 0) while (this -> numbers[current_row][current_col] == 0) current_col++;
    

    while((current_col >= 0) && (current_row >= 0)){

        if(this -> ZeroCol(current_row, current_col)) --current_col;

        else{

            ZerosUpperMain(current_row, current_col);

            --current_row;
            --current_col;
        }
    }

    printAndCheckAnswer(X, A, B);
}
