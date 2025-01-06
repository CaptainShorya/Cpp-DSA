#include <iostream>
using namespace std;

void print(int n){
    //base case
    if(n == 0){
        return;
    }
    cout << n << endl; //kaam
    print(n - 1); //faith , next call
}

int main(){
    print(5);
    return 0;
}