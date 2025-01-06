#include <iostream>
using namespace std;
int main (){
    int num;
    int sum = 0;
    cout<<"Enter n : ";
    cin >> num;
    for(int i = 1;i<=num;i++){
        sum = sum + i;
    }
    cout<<sum<<endl;
}