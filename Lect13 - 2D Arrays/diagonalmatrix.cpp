#include <iostream>
using namespace std;

int diagonalmatrix(int matrix[][3],int n){
    int sum = 0;

    // O(n^2)
    // for(int i=0; i<n; i++){ //Rows
    //     for(int j=0; j<n; j++){ //Cols
    //         //Primary Diagonal
    //         if(i == j){
    //             sum += matrix[i][j];
    //         }else if(j == n-i-1){
    //             sum += matrix[i][j];
    //         }

    //         If we do not use else if in uppar code
    //         //Secondary Diagonal 
    //         if(i == n-j-1){
    //             if(i == j){
    //                 continue;
    //             }
    //             sum += matrix[i][j];
    //         }
    //     }

    //Time Complexity - O(n)
    for(int i=0; i<n; i++){ 
        sum += matrix[i][i]; //Primary Diagonal

       if(i != n-i-1){ //Secondary Diagonal 
       //Used not equal to eliminate readdition of middle most term in odd matrix
        sum += matrix[i][n-i-1];
       } 
        
    }
    return sum;
}
int main(){
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int sum = diagonalmatrix(matrix,3);
    cout << "Sum of Diagonal Matrix : " << sum;
    return 0;
}