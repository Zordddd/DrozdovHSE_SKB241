#include <iostream>
#include <time.h>
#include <iomanip>
#define ___TESTS___(first, second) cout << "Start data --> " << first << "; Finish data --> " << second;**\
    if (absolute(second - ans(first)) > 0.0000000001) cout << "; Uncorrect\n";**\
    else cout << "; Correct\n";


using namespace std;


long double power(long double num, long deg) {
    long double result = 1.0;

    for(long i = 0; i < deg; i++) {
        result *= num;
    }

    return result;
}


long double absolute(long double x){
    return (x < .0 ? -x : x);
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


long double ans(long double y){
    return (7 * t(0.25) + 2 * t(1 + y)) / (6 - t(power(y, 2) - 1));
}


int main(void){

    long double y, answer;
    cin >> y;
    int start = clock();
    
    answer = ans(y);

    cout << "Answer " << setprecision(20) << (answer) << "\n";


    int finish = clock();
    cout << "Time: " << setprecision(20) << (double(finish - start) / 1000.0) << "\n" << endl;


    ___TESTS___(5, -10.3181) // correct answer : -10.31812865314951527078
    ___TESTS___(1, ans(1))
    ___TESTS___(100, ans(100))
    ___TESTS___(1000, ans(1000))
    ___TESTS___(123456, ans(123456))

    return 0;
}
