#include <iostream>
#include <cmath>
using namespace std;
int main(){
    //Q1
    // for(int i=0; i<=3; i++){
    //     cout<<"****"<<endl;
    // }

    //Q2
    // int m;
    // cout<<"Enter a number";
    // cin >> m;
    // for(int i=m; i>=1 ; i--){
    //     cout<<i<<" ";
    // }
    
    //To access last digit of number, use -> number % 10 this will return last digit of the given number 
    //To remove last digit from a number, divide the number by 10 -> num - num / 10 this will return the value after removing the last digit 
    //Q3
    // int num = 10829;
    // int sum = 0;
    // while(num > 0){
    //     int digit= num % 10;
    //     sum = sum + digit;
    //     num = num/10;
    // }
    // cout<<sum;

    //Q4
    // int num = 10829;
    // int sum = 0;
    // while(num > 0){
    //     int digit= num % 10;
    //     if(digit % 2 == 1){
    //         sum = sum + digit;
    //     }
    //     num = num/10;
    // }
    // cout<<sum;

    //Q5 -> Print the digits of a number in reverse using while loop.
    // int num = 10829;
    // while(num > 0){
    //     int lastdigit = num % 10;
    //     cout<<lastdigit;
    //     num = num /10;
    // }

    //Q6 -> Reverse a given number and print the result
    int res = 0;
    int num = 10829;
    while(num > 0){
        int lastDigit = num % 10;
        res = res*10 + lastDigit;//Logic to reverse a number and store it in a variable 
        num = num/10;
    }
    cout<<res;
}