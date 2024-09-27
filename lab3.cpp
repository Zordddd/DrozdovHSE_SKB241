#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

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


int main(void){

    int n;
    cin >> n;
    long long int cups1[n/2], sums1[(long long int)pow(2, n/2)], sums2[(long long int)pow(2, n/2 + n%2)];
    long long int cups2[n/2 + n % 2];
    long long int sum = 0;
    long long int min_diff = 1000000000000, min_diff_h = 1000000000000;


    for (long long int i = 0; i < n / 2; i++){
        
        long long int num;
        cin >> num;
        cups1[i] = num;
        sum += num;
    }

    for (long long int i = 0; i < (n / 2) + (n % 2); i++){
        
        long long int num;
        cin >> num;
        // cin >> num;
        cups2[i] = num;
        // cout << num << "\n";
        sum += num;
    }


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
    
    // for (int i = 0; i < pow(2, n / 2); i++) cout << sums1[i] << " ";
    //cout << "\n";
    //for (int i = 0; i < pow(2, n / 2 + n % 2); i++) cout << sums2[i] << " ";
    //cout << "\n";
    
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
    cout << "time - " << double(finish - start) / CLOCKS_PER_SEC << endl;


    return 0;
}
