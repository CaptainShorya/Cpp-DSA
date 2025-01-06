#include <iostream>
using namespace std;

//Reference variable requires an initializer. //int &b; Give error
int main(){
    int a = 10;
    int &b = a; //Now a and b have same memory location.
    b = 25;
    cout<<b<<endl; //25
    cout<<a<<endl; //25
    return 0;
}
