#include <iostream>
using namespace std;

void isPrime(int n);//Function declare

bool Prime(int n);//function declare

int main(){
    // isPrime(10);
    cout<<Prime(2);
    return 0;
}

//Approach 1
void isPrime(int n){
    int flag = 0;
    for(int i=2; i<n; i++){
        if(n%i == 0){
            cout<<"Not a Prime Number";
            flag = 1;
            break;
        }
    }
    if(!flag){
        cout<<"Prime Number";
    }
}

//Approach 2
//After return statement execution in any of the condition, no further code execution in that function will take place
bool Prime(int n){
    if(n == 1){
        return false;
    }
    for(int i=2; i<n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

