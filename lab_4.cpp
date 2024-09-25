#include <iostream>
#include <time.h>
using namespace std;

void print_partition(long long n) {
    if (n % 4 == 1 || n % 4 == 2) {
        cout << "Answer: No\n";
        return;
    }


    long long int polusum = n * (n + 1) / 4, current = n, flag, num = 1;
    cout << "Answer: Yes\n";
    long long lenght1 = 1;


    cout << "First person part:\n" << current << " ";
    for (long long int i = n - 1; i >= 1; i--){
        if (current + i <= polusum){                
            cout << i << " ";
            current += i;
            lenght1++;
        }

        else {
            
            cout << polusum - current << "\n";
            num = i;
            flag = polusum - current;
            lenght1++;
            break;
                
        }
    }


    cout << "Second group:\n";
    for (; num >= 1; num--){
        if (num != flag) cout << num << " ";
    }
    
    
    cout << "\nLenght of first group: " << lenght1 << "\n";
    cout << "Lenght of second group: " << n - lenght1 << "\n";

}

int main() {
    long long n;
    cin >> n;
    int start = clock();
    print_partition(n);
    int finish = clock();
    cout << "Time of process: "<< (double)(finish - start) / 1000.0 << endl;
    return 0;
}
