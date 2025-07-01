#include <iostream>
using namespace std;

void print1ToN(int val){
    if(val == 0) return;
    cout << val << " ";
    print1ToN(val-1);
}

void printNto1(int val){
    if(val == 0) return;
    printNto1(val-1);
    cout << val << " ";
}

int main(){
    print1ToN(10);
    cout << endl;
    printNto1(10);
}