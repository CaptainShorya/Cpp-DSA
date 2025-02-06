#include <iostream>
#include <vector>
using namespace std;

//N Queens -> Place N queens on a NxN chessboard such that no 2 queens can attack each other

void printArr(vector<vector<char>> board){
    int n = board.size();

    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------------------\n";
}

bool isSafe(vector<vector<char>> board, int row, int col){
    int n = board.size();
    //horizontal
    for(int j=0; j<n; j++){
        if(board[row][j] == 'Q'){
            return false;
        }
    }

    //vertical
    for(int i=0; i<row; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }

    //diagonal left
    for(int i=row,j=col; i>=0 && j>=0; i--,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    //diagonal right
    for(int i=row, j=col; i>=0 && j<n; i--,j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

int nQueens(vector<vector<char>> board, int row){ // ith row -> ith Queen 
    int n = board.size();

    //Base Case
    if(row == n){
        printArr(board);
        return 1;
    }

    int count = 0;
    for(int j=0; j<n; j++){
        if(isSafe(board,row,j)){
            board[row][j] = 'Q';
            count += nQueens(board,row+1);
            board[row][j] = '.'; // Back-tracking , Before setting up new position of Q, we have to remove Q from its existing position.
        }
         
    }
    return count;
}

int main(){
    vector<vector<char>> board;
    int n = 4;

    for(int i=0; i<n; i++){
        vector<char> newRow;
        for(int j=0; j<n; j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }

    int count = nQueens(board,0);
    cout << "Count : " << count << endl;
    return 0;

}