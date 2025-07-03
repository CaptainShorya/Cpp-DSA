#include<iostream>
using namespace std;

//Number of ways to climb n steps = Steps taken to climb n-1 steps + Steps taken to climb n-2 steps
int stairCase(int n){
    if(n == 2 || n == 1) return n;
    return stairCase(n-1) + stairCase(n-2);
}

int main(){
    cout <<"Number of ways to reach at top = ";
    cout << stairCase(4) << endl;
}