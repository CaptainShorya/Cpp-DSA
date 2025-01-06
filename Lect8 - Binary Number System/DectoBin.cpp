#include <iostream>
#include <cmath>
using namespace std;

//Convert from decimal to Binary
void DectoBin(int DecNum){
    int n = DecNum;
    int pow = 1;
    int Binnum = 0;
    while(n>0){
        int rem = n % 2;
        n = n / 2;
        Binnum = Binnum + rem * pow;
        pow = pow * 10;
    }

    cout<<Binnum<<endl;
    
}

int main(){
    DectoBin(7);
    return 0;
}