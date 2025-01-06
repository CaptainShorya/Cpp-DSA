#include <iostream>
using namespace std;

int getIthbit(int num,int i){
    int mask = 1<<i;
    if((num & mask)){
        return 1;
    }else{
        return 0;
    }
}

int setIthbit(int num,int i){
    int bitmask = 1 << i;
    return (num | bitmask);
}

int clearIthbit(int num,int i){
    int bitmask = ~(1<<i);
    return num & bitmask;

}

bool isPowerof2(int num){
    if(!(num & (num-1))){
        return true;
    }else{
        return false;
    }
}

int updateIthbit(int num, int i, int val){
    num = num & ~(1<<i); //clear ith bit
    num = num | (val<<i); //update ith bit
    cout << num << endl;
}

int clearIbits(int num, int i){
    int bitmask = (~0)<<i;
    num = (num & bitmask);
    return num;
}

void countSetBits(int num){
    int count = 0;

    while(num > 0){
        int lastDigit = (num & 1);
        count += lastDigit;
        num = num >> 1;
    }
    cout <<"Count of Set Bits is : "<< count <<endl;
}


int main(){
    // cout << getIthbit(6,2) << endl;
    // cout << setIthbit(6,3) << endl;
    // cout << clearIthbit(6,1) << endl;
    // cout << isPowerof2(4) << endl;
    // updateIthbit(7,2,0);
    // cout << clearIbits(15,2);
    countSetBits(10);
    return 0;
}