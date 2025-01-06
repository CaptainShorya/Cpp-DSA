#include <iostream>
using namespace std;

void func(int mat[][4], int n, int m){
    cout << "0th row pointer : " << mat << endl;
    cout << "1th row pointer : " << mat+1 << endl;
    cout << "2th row pointer : " << mat+2 << endl;

    cout << "0th row value : " << *(mat) << endl;
    cout << "1th row value : " << *(mat + 1) << endl;
    cout << "2th row value : " << *(mat + 2) << endl;

    cout << *(*(mat + 2) + 2) << endl;
}

int main(){
    int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    func(matrix,4,4);
    return 0;
}