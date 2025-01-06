#include <iostream>
using namespace std;

//WAP to find binomial coeffiecient of n and r. //Example - Selection of 2 books out of 4 books.
int factorial(int n){
    int fact = 1;
    for(int i=n; i>=1; i--){
        fact = fact * i;
    }
    return fact;
}

int binCoeff(int n,int r){
    return factorial(n)/(factorial(r)*factorial(n-r));
}


int main(){
    cout<<binCoeff(4,2)<<endl;
}