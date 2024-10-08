#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>

#define TEST1 "test1-lab3.txt"
#define TEST2 "test2-lab3.txt"
#define TEST3 "test3-lab3.txt"
#define TEST4 "test4-lab3.txt"
#define TEST5 "test5-lab3.txt"
using namespace std;

int test1_ans = 1;
int test2_ans = 0;
int test3_ans = 0;
int test4_ans = 4;
int test5_ans = 1;


void qsortRecursive(long long int *mas, long long int size) {
    long long int i = 0;
    long long int j = size - 1;

    long long int mid = mas[size / 2];

    do {
        while(mas[i] > mid) {
            i++;
        }
        while(mas[j] < mid) {
            j--;
        }

        if (i <= j) {
            long long int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    if(j > 0) {
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
        qsortRecursive(&mas[i], size - i);
    }
}

long long int CreateTwoArrays(long long *cups1,long long *cups2, char name_file[]){
    long long int len, num, i, sum = 0;

    ifstream file;
    file.open(name_file);

    if (file.is_open()){

        file >> len;

        for (i = 0; i < len / 2; i++){
            file >> num;
            cups1[i] = num;
            sum += num;
        }

        for (i = 0; i < len / 2 + len % 2; i++){
            file >> num;
            cups2[i] = num;
            sum += num;
        }

        file.close();

    }


    return sum;
}

int main(void){
    int n;
    char file[] = TEST5;
    ifstream f;
    f.open(file);
    if (f.is_open()) f >> n;
    f.close();


    long long int cups1[n/2], cups2[n/2 + n % 2], sums1[(long long int)pow(2, n/2)], sums2[(long long int)pow(2, n/2 + n%2)];;
    long long int sum = CreateTwoArrays(cups1, cups2, file);
    long long int min_diff = 1000000000000, min_diff_h = 1000000000000;
    int start = clock();

    for (long long int mask = 0; mask < pow(2, n/2); mask++){
        long long int cur_sum = 0;
        for (long long int i = 0; i < n / 2; i++){
            if ((mask & (1 << i)) != 0){
                cur_sum += cups1[i];
            }
        }
        sums1[mask] = cur_sum;
    }

    for (long long int mask = 0; mask < (long long int)pow(2, n/2 + n%2); mask++){
        long long int cur_sum = 0;
        for (long long int i = 0; i < n / 2 + n%2; i++){
            if ((mask & (1 << i)) != 0){
                cur_sum += cups2[i];
            }
        }
        sums2[mask] = cur_sum;
    }
    

    qsortRecursive(sums1, (long long int)pow(2, n/2));
    qsortRecursive(sums2, (long long int)pow(2, n/2 + n%2));
    
    
    for (long long int i = 0; i < (long long int)pow(2, n/2); i++){
        long long int left = 0, right = (long long int)pow(2, n / 2 + n % 2) - 1, mid = (right + left) / 2;
        while (left <= right){
            if ((sums1[i] + sums2[mid]) < (sum / 2)){
                right = mid - 1;
                mid = (right + left) / 2;
            }
            else if ((sums1[i] + sums2[mid]) > (sum/2)) {
                left = mid + 1;
                mid = (right + left) / 2;
            }
            else {
                break;
            }
        }
        if (min_diff_h > abs(sum / 2 - (sums1[i] + sums2[mid]))){
            min_diff = min(min_diff, (sums1[i] + sums2[mid]));
            min_diff_h = abs(sum / 2 - (sums1[i] + sums2[mid]));
        }
    }
    
    int finish = clock();


    cout << "answer - " <<  abs(sum - min_diff * 2) << "\n";
    if (abs(sum - min_diff * 2) == test5_ans) cout << "Test is passed\n";
    else cout << "Test is not passed\n";
    cout << "time - " << double(finish - start) / CLOCKS_PER_SEC << endl;


    return 0;
}
