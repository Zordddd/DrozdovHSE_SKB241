#include <iostream>
using namespace std;


void hanoi(int count_of_cycle, int current, int free, int target){

    if (count_of_cycle == 0)
        return;
    

    hanoi(count_of_cycle - 1, current, target, free);
    cout << current << ">>" << target << endl;
    hanoi(count_of_cycle - 1, free, current, target);


    return;

}


int main(void){

    hanoi(3, 1, 2, 3);
    cout << endl;
    
    return 0;
}