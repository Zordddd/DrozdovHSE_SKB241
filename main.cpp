#include <iostream>
#include "Matrix.hpp"

#define FILE "text.txt"

void interface(){

    Matrix matrix1, matrix2;
    char c;
    int choice;
    bool work_oprations = true, work_matrices = false;


    do{
        std::cout << "Pick a variation of input first matrix(write number 1 or 2):" << std::endl <<
                    "1. File" << std::endl << "2. Terminal" << std::endl << "3. exit" << std::endl;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cout << "Invalid input, please enter a number." << std::endl;
            std::cin.clear();
            while (std::cin.get(c) && c != '\n');
            work_matrices = true;
            continue;
        }
        else work_matrices = false;

        switch (choice)
        {
        case 1:
            matrix1.getMatrix(FILE);
            break;
        
        case 2:
            std::cout << "Write matrix: ";
            matrix1.getMatrix();
            break;
        
        case 3:
            return;
        default:
            std::cout << "Wrong number of input variation...";
            return;
        }
    }while(work_matrices);

    do{
        std::cout << "Pick a variation of input second matrix(write number 1 or 2):" << std::endl <<
                    "1. File" << std::endl << "2. Terminal" << std::endl << "3. exit" << std::endl;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cout << "Invalid input, please enter a number." << std::endl;
            std::cin.clear();
            while (std::cin.get(c) && c != '\n');
            work_matrices = true;
            continue;
        }
        else work_matrices = false;

        switch (choice)
        {
        case 1:
            matrix2.getMatrix(FILE);
            break;
        
        case 2:
            std::cout << "Write matrix: ";
            matrix2.getMatrix();
            break;
        
        case 3:
            return;
        
        default:
            std::cout << "Wrong number of input variation...";
            return;
        }
    }while(work_matrices);


    while (work_oprations){
        std::cout << "Pick an operation(write number):" << std::endl << "0. Gauss first matrix" << std::endl        <<
                    "1. Gauss second matrix" << std::endl << "2. +" << std::endl << "3. -" << std::endl             <<
                    "4. * matrix" << std::endl << "5. * number" << std::endl                                        << 
                    "6. ==" << std::endl << "7. !=" << std::endl << "8. print first matrix" << std::endl            <<
                    "9. print second matrix" << std::endl << "10. print first matrix in file" << std::endl          <<
                    "11. print first matrix in file" << std::endl << "12. exit" << std::endl;

        std::cin >> choice;
        if (std::cin.fail()) {
            std::cout << "Invalid input, please enter a number." << std::endl;
            std::cin.clear();
            while (std::cin.get(c) && c != '\n');
            continue;
        }

        switch (choice)
        {
            int number;

        case 0:
            std::cout << "---------------" << std::endl;
            matrix1.Gauss();
            std::cout << "---------------" << std::endl;

            break;
        case 1:
            std::cout << "---------------" << std::endl;
            matrix2.Gauss();
            std::cout << "---------------" << std::endl;
            break;
        case 2:
            std::cout << "---------------" << std::endl;
            (matrix1 + matrix2).printMatrix();
            std::cout << "---------------" << std::endl;
            break;
        case 3:
            std::cout << "---------------" << std::endl;
            (matrix1 - matrix2).printMatrix();
            std::cout << "---------------" << std::endl;
            break;
        case 4:
            std::cout << "---------------" << std::endl;
            (matrix1 * matrix2).printMatrix();
            std::cout << "---------------" << std::endl;
            break;
        case 5:
            std::cout << "---------------" << std::endl;
            std::cout << "Write number: ";
            std::cin >> number;
            if (std::cin.fail()) {
                std::cout << "Invalid input, please enter a number." << std::endl;
                std::cin.clear();
                while (std::cin.get(c) && c != '\n');
                continue;
            }
            
            std::cout << "Write number of matrix(1 or 2): ";
            std::cin >> choice;

            if (std::cin.fail()) {
                std::cout << "Invalid input, please enter a number." << std::endl;
                std::cin.clear();
                while (std::cin.get(c) && c != '\n');
                continue;
            }
            if (choice == 1) (matrix1 * number).printMatrix();
            if (choice == 2) (matrix2 * number).printMatrix();

            std::cout << "---------------" << std::endl;
            break;
        case 6:
            std::cout << "---------------" << std::endl;
            std::cout << (matrix1 == matrix2) << std::endl;
            std::cout << "---------------" << std::endl;
            break;
        case 7:
            std::cout << "---------------" << std::endl;
            std::cout << (matrix1 != matrix2) << std::endl;
            std::cout << "---------------" << std::endl;
            break;
        case 8:
            std::cout << "---------------" << std::endl;
            matrix1.printMatrix();
            std::cout << "---------------" << std::endl;
            break;
        case 9:
            std::cout << "---------------" << std::endl;
            matrix2.printMatrix();
            std::cout << "---------------" << std::endl;
            break;
        case 10:
            matrix1.printMatrix_in_file("matrix1.txt");
            break;
        case 11:
            matrix2.printMatrix_in_file("matrix2.txt");
            break;
        case 12:
            work_oprations = false;
            break;
        
        default:
            std::cout << "Wrong number of operation..." << std::endl;
            break;
        }
    }
}


int main()
{
    interface();

    return 0;
}
