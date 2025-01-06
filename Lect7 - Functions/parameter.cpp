#include <iostream>
using namespace std;

int sum(int a, int b=1){// a,b are parameters
    int sum = a + b;
    return sum;
}
int pro(int a,int b){
    int pro = a * b;
    return pro;
}
int oddOrEven(int n){
    if(n%2 == 0){
        cout<<"Number is Even";
        return 0;
    }else{
        cout<<"Number is Odd";
        return 0;
    }
}

int main(){
    int s = sum(2,8); // 2,8 are arguments
    int p = pro(10,5);
    cout<<"Sum is = "<<s<<endl;
    cout<<"Product is = "<<p<<endl;
    oddOrEven(15);
    return 0;
}