#include <iostream>
using namespace std;

void printPath(string path,int sr, int sc, int er, int ec){
    //Base Case
    if(sr > er || sc > ec) return;
    if(sr == er && sc == ec) cout << path << endl;

    printPath(path+"R",sr,sc+1,er,ec);
    printPath(path+"D",sr+1,sc,er,ec);
}

int maze(int sr, int sc, int er, int ec){
    //Base Case
    if(sr > er || sc > ec) return 0;
    if(sr == er && sc == ec) return 1;

    int rightWays = maze(sr,sc+1,er,ec);
    int downWays = maze(sr+1,sc,er,ec);
    return rightWays + downWays;
}

int main(){
    cout << maze(0,0,2,2) << endl;
    printPath("",0,0,2,2);
}