#include <iostream>
using namespace std;

void changeA(int param){//param is a copy of argument variable (which is a)
    param = 20;
    cout<<param<<endl;
}

int main(){
    int a = 20;
    changeA(a); //20
    cout<<a<<endl; //10
    return 0;
}