#include <iostream>
#include <vector>
using namespace std;

//N Queens -> Place N queens on a NxN chessboard such that no 2 queens can attack each other

// void printArr(vector<char> board){
//     int n = board.size();

//     for(int i =0; i<n; i++){
//         for(int j=0; j<n; j++){
//             cout << board[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

void nQueens(vector<vector<char>> board, int row){ // ith row -> ith Queen 

}

int main(){
    vector<vector<char>> board;
    int n = 2;

    for(int i=0; i<n; i++){
        vector<char> newRow;
        for(int j=0; j<n; j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    return 0;

}