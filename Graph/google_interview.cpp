#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<char>> vec = {
        {'R','R','D','R'},
        {'D','U','D','L'},
        {'U','U','L','R'},
        {'U','R','R','R'}
    };
    int m = vec.size();
    int n = vec[0].size();
    int count = 0;
    int r = 0;
    int c = 0;
    bool hasReach = false; 
    while(r >= 0 && c >= 0 && r < m && c < n){
        if(r == m-1 && c == n-1){
            hasReach = true;
            break;
        }
        if(count >= n*m){
            hasReach = false;
            break;
        }
        count++;
        if(vec[r][c] == 'R'){
            c++;
        }else if(vec[r][c] == 'L'){
            c--;
        }else if(vec[r][c] == 'D'){
            r++;
        }else if(vec[r][c] == 'U'){
            r--;
        }
    }
    cout << hasReach << endl;
    if(count == m*n) cout << "Never reach destination" << endl;
    else cout << "Total Steps required to reach destination : " << count << endl;
    return 0;
}