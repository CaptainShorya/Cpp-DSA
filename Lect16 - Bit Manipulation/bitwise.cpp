#include <iostream>
using namespace std;

int main(){
    //Bitwise Operator 
    cout << (3 & 5) << endl ;
    cout << (3 | 5) << endl ;
    cout << (3 ^ 5) << endl ;

    //1's Compliment & 2's Compliment form
    cout << (~6) << endl;
    cout << (~0) << endl;

    //Bitwise Shift Operator
    cout << (7 << 2) << endl;
    cout << (7 >> 2) << endl;
    return 0;
}