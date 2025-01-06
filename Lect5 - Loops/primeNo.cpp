#include <iostream>
#include <cmath>
using namespace std;
int main(){
    //Check whether a number is prime or not.
    int n;
    bool isPrime = true;
    cout<< "Enter a number : ";
    cin >> n;
    for(int j=2; j<n; j++){
        if(n%j == 0){
            cout<<"Not a prime Number";
            isPrime = false;
            break;
        }
    }
    if(isPrime){
        cout<<"Prime Number";
    }else{
        cout<<"Not a Prime";
    }


}