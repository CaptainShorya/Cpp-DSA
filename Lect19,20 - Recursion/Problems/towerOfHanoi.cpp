#include <iostream>
using namespace std;

void hanoi(int n, char a, char b, char c){ // Always (source, helper, destination)
    if(n == 0) return; // base case
    hanoi(n-1,a,c,b); // a -> source , b-> destination , c -> helper // smaller subproblem
    cout << a <<" -> "<< c <<endl; // actual action (move)
    hanoi(n-1,b,a,c); //  b -> source , a-> helper , c -> destionation  // another smaller subproblem
}

int main(){
    int n = 3;
    hanoi(n,'A','B','C');
}