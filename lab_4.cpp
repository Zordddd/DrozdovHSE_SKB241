#include <iostream>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;


void print_partition(long long n) {
    if (n % 4 == 1 || n % 4 == 2) {
        cout << "Answer: No\n";
        return;
    }


    long long int polusum = n * (n + 1) / 4, current = n, flag, num = 1;
    cout << "Answer: Yes\n";
    long long lenght1 = 1;

    ofstream file;

    file.open("CurrentTest.txt");

    if (file.is_open()){
        file << "First person:\n" << current << " ";
        for (long long int i = n - 1; i >= 1; i--){
            if (current + i <= polusum){                
                file << i << " ";
                current += i;
                lenght1++;
            }

            else {
                
                file << polusum - current << "\n";
                num = i;
                flag = polusum - current;
                lenght1++;
                break;
                    
            }
        }


        file << "Second person:\n";
        for (; num >= 1; num--){
            if (num != flag) file << num << " ";
        }
        
        
        file << "\nLenght of first group: " << lenght1 << "\n";
        file << "Lenght of second group: " << n - lenght1 << "\n";
    }

    file.close();
}


void FilesEqual(char name_of_file1[], char name_of_file2[]){

    ifstream file1(name_of_file1),  file2(name_of_file2);

    if(file1.is_open() && file2.is_open()){
        string str1, str2;

        while (getline(file1, str1) && getline(file2, str2)){
            int equal = str1 == str2;

            if (!equal) {
                cout << "Answer is wrong(or you input wrong number)\n";
                return;
            }
        }
    }

    file1.close();
    file2.close();

    cout << "Answer is right!\n";
    
}


int main() {
    char filename1[] = "CurrentTest.txt";
    char filename2[] = "test2_lab4.txt";
    long long n;
    cin >> n;

    int start = clock();


    print_partition(n);
    FilesEqual(filename1, filename2);


    int finish = clock();
    cout << "Time of process: "<< (double)(finish - start) / 1000.0 << endl;


    return 0;
}
