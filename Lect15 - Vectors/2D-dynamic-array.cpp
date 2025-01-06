#include <iostream>
using namespace std;

int main(){
    int rows,cols;
    cout << "Enter Rows : ";
    cin >> rows;
    cout << "Enter Columns : ";
    cin >> cols;

    //2D Dynamic Array
    int* *matrix = new int*[rows];

    for(int i=0; i<rows; i++){
        matrix[i] = new int[cols];
    }

    //Data Store
    int x=1;
    for(int i=0; i<rows; i++){
       for(int j=0; j<cols; j++){
            matrix[i][j] = x++;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << matrix[2][2] << endl; // 9
    cout << *(*(matrix+2)+2) << endl; // 9

    return 0;
}