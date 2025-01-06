#include <iostream>
using namespace std;

//pass by reference by pointers
void changeA(int *ptr){
    *ptr = 20;
    cout << *ptr << endl;
}

//pass by reference by reference variable
void changeB(int &param){ 
    param = 2;
    cout<<param<<endl;
}

int main(){
    int a = 10;
    //pointers
    changeA(&a); // 20
    cout << a << endl; //20

    //reference variable
    int b = 1;
    changeB(b); //2
    cout<<b<<endl; //2
}