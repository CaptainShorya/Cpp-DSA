#include <iostream>
using namespace std;

void oddOReven(int num){
    if(num & 1){
        cout << "Number is Odd" << endl;
    }else{
        cout << "Number is Even" << endl;
    }
}

int main(){
    int num;
    cin >> num;
    oddOReven(num);
    return 0;
}
