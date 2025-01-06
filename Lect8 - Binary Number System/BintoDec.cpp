#include <iostream>
#include <cmath>
using namespace std;

//Convert from Binary to Decimal

//Approach by me using cmath library
void BintoDec(int binNum){
    int n = binNum;
    int exp = 0;
    int decNum = 0;
    while(n>0){
        int lastDigit = n % 10;
        n = n / 10;
        decNum = decNum + lastDigit * pow(2,exp); 
        exp++;
    }
    cout<<decNum<<endl;
}

//Approach By Mam without cmath library (Understand this)
void BintoDec2(int binNum){
    int n = binNum;
    int pow = 1; //2^0 2^1 2^2 ...
    int decNum = 0;
    while(n>0){
        int lastDigit = n % 10;
        decNum = decNum + lastDigit * pow;
        pow = pow * 2;
        n = n / 10;
    }
    cout<<decNum<<endl;
}

int main(){
    BintoDec(101);
    return 0;
}