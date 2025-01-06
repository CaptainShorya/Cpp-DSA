#include <iostream>
using namespace std;

//recursive function - eg Factorial of a number
int factorial(int n){
    //base case
    if(n == 0){
        return 1;
    }
    return n*factorial(n-1);
}

int main(){
    int ans = factorial(5);
    cout << ans << endl;
    return 0;
}