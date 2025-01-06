#include <iostream>
using namespace std;

//Function overloading
int sum(int a,int b){
    return a+b;
}

//Based on type
double sum(double a,double b){
    return a+b;
}
//Based on Number of parameters
int sum(int a,int b,int c){
    return a+b+c;
}

int main(){
    cout<<sum(1,2)<<endl;
    cout<<sum(1.5,2.5)<<endl;
    cout<<sum(1,2,3)<<endl;
}