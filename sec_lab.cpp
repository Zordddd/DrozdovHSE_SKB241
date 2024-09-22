#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;


int factorial2(int k){
    int res = 1;
    if (k % 2) {
        for (int i = 1; i <= k; i += 2){
            res *= i;
        }
    }    
    else {
        for (int i = 2; i <= k; i += 2){
            res *= i;
        }
    }

    return res;
}


double t(double x){
    double res1 = 0, res2 = 0;

    for (int k = 0; k <= 10; k++){
        res1 += pow(x, 2 * k + 1) / factorial2(2 * k + 1);
        res2 += pow(x, 2 * k) / factorial2(2 * k);
    }

    return res1 / res2;

}


int main(void){

    double y, answer;
    cin >> y;
    int start = clock();

    answer = (7 * t(0.25) + 2 * t(1 + y)) / (6 - t(y * y - 1));

    cout << (answer) << "\n";

    int finish = clock();
    cout << (double(finish - start) / CLOCKS_PER_SEC) << "\n";
    cout << t(0.25);
    return 0;
}