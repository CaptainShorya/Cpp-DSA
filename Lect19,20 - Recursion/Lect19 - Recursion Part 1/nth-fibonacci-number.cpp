#include <iostream>
using namespace std;

int fibonacci(int n){
    //Base case
    if(n == 0 || n==1){
        return n;
    }

    //kaam 
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    cout << fibonacci(5) << endl;
    return 0;
}