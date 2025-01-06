#include <iostream>
using namespace std;

void spiralmatrix(int matrix [][3],int n, int m){
    int srow = 0, scol = 0;
    int erow = n-1, ecol = m-1;

    while(srow <= erow && scol <= ecol){
        //top
        for(int j=scol; j<=ecol; j++){
            cout << matrix[srow][j] <<" ";
        }

        //right
        for(int i=srow+1; i<=erow; i++){
            cout << matrix[i][ecol] <<" ";
        }
        
        //bottom
        for(int j=ecol-1; j>=scol; j--){
            if(srow == erow){ //Stops Reprinting 
                break;
            }
            cout << matrix[erow][j] <<" ";
        }

        //left
        for(int i=erow-1; i>=srow+1; i--){
            if(srow == erow){ //Stops Reprinting
                break;
            }
            cout << matrix[i][scol] <<" ";
        }

        srow++ , scol++;
        erow-- , ecol--;
    }
    
}

int main(){
    int matrix[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    spiralmatrix(matrix,4,3);
    return 0;
}