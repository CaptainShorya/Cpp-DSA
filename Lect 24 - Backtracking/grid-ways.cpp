#include <iostream>
#include <vector>
using namespace std;

// Find number of ways to reach from (0,0) to (N-1,M-1) in a NxM Grid.
//Allowrd moves - right or down

int gridWays(int r, int c, int n, int m, string ans){
    if(r == n-1 && c == m-1){
        //Destination reached
        cout << ans << endl;
        return 1;
    }

    if(r > n-1 || c > m-1){
        return 0;
    }
    //Right Move
    int v1 = gridWays(r,c+1,n,m,ans+"R");

    //Down Move
    int v2 = gridWays(r+1,c,n,m,ans+"D");

    return v1 + v2;
}

int main(){
    int n = 3;
    int m = 3;
    string ans = "";

    cout << "Total Ways to reach destination from Source = " << gridWays(0,0,n,m,ans) << endl;
    return 0;
}