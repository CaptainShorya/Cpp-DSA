#include <iostream>
using namespace std;

int factorial(int n);//function declare

int main(){
    int num;
    cout<<"Enter a number = ";
    cin >> num;
    cout<<"Factorial of "<<num<<" is = "<<factorial(num);
    return 0;
}

int factorial(int n){
    int fact = 1;
    for(int i=n; i>=1; i--){
        fact = fact * i;
    }
    return fact;
}