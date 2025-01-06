#include <iostream>
using namespace std;

//Forward Declaration
void sayhello(); //function Declare

int main(){
    sayhello(); //function call
    return 0;
}

void sayhello(){ //No error occur as function is declared initially before main function.
    cout<<"Hello World This side function";
}