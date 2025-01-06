#include <iostream>
using namespace std;
int main(){
    int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    cout << matrix << endl; //Pointer - 0x61fed0
    cout << matrix << " = " << &matrix[0][0] << endl; //True
    cout << matrix+1 << " != " << &matrix[0][1] << endl; //True
    cout << matrix+1 << " = " << &matrix[1][0] << endl; //True
    return 0;
}