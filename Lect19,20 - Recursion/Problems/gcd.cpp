#include <iostream>
using namespace std;

//Greatest Common Divisor of Two Numbers

//Method 1 -> Brute Force Approach
int gcd_brute(int a, int b){
    for(int i=min(a,b); i>=2; i--){
        if(a%i==0 && b%i==0) return i;
    }
    return 1;
}


//Method 2 : Recursively (Euclid's Division Algo -> Long Division Method)
// TC : O(log(a+b))
int gcd_optimal(int a, int b){
    int r = b%a;
    if(r==0) return a;
    return gcd_optimal(r,a);
}

int main(){
    int a = 45;
    int b = 27;
    cout << "HCF: " << gcd_optimal(a,b) <<endl;
    cout << "HCF: " << gcd_brute(a,b);
}