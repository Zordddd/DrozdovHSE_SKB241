#include <iostream>
#include <time.h>
// #include <math.h>
using namespace std;


long double power(long double num, long deg) {
    long double result = 1.0;

    for(long i = 0; i < deg; i++) {
        result *= num;
    }

    return result;
}


long long int factorial2(long long int k){
    if (k <= 1) return 1;
    else return k*factorial2(k-2);
}


long double t(long double x){
    long double res1 = 0.0, res2 = 0.0;

    for (long double k = 0.0; k <= 10.0; k += 1.0){

        res1 += (power(x, 2 * k + 1) / factorial2(2 * k + 1));
        res2 += (power(x, 2 * k) / factorial2(2 * k));
    }

    return res1 / res2;
}


int main(void){

    long double y, answer;
    cin >> y;
    int start = clock();
    
    answer = (7 * t(0.25) + 2 * t(1 + y)) / (6 - t(power(y, 2) - 1));

    cout << "Answer " << (answer) << "\n";

    int finish = clock();
    cout << "Time: " << (double(finish - start) / CLOCKS_PER_SEC) << "\n" << endl;

    return 0;
}
