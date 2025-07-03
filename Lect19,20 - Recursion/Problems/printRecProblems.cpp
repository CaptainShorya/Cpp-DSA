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

int sum1ToN(int val){
    if(val == 1) return 1;
    return val+sum1ToN(val-1);
}

int power(int base, int exp){
    if(exp == 0) return 1;
    return base*power(base,exp-1);
}

int fibonacci(int n){
    if(n == 1 || n == 2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

//Time Complexity -> O(log n) , Space Complexity -> O(log n) 
int powerLog(int base, int exp){
    if(exp == 1 || exp == 0) return base;
    if(exp % 2 != 0){
        int ans = powerLog(base,(exp-1)/2);
        return base*ans*ans;
    }else{
        int ans = powerLog(base,exp/2);
        return ans*ans;
        //return powerLog(base,exp/2)*powerLog(base,exp/2);
        //64 -> 32,32 -> 16,16 16,16 -> ..... ==> 1 + 2 + 4 + 8 + .... = 2^n - 1
        //If this was performed again, the time complexity will be of Order of n.
    }
}

int main(){
    print1ToN(10);
    cout << endl;
    printNto1(10);
    cout << endl;
    cout<<sum1ToN(10);
    cout << endl;
    cout << power(2,10);
    cout << endl;
    cout << fibonacci(5);
    cout << endl;
    cout << powerLog(3,9);
}
