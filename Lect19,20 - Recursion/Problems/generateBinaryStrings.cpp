#include <iostream>
using namespace std;

// Generate all binary strings of length n
void all_binary_strings(string a,int length){
    if(a.length() == length){
        cout << a << endl;
        return;
    }
    all_binary_strings(a+"0",length);
    all_binary_strings(a+"1",length);
}

// Generate all binary strings of length n without consecutive 1's
void all_binary_strings_without_consecutive_1s(string a,int length,int i){
    if(a.length() == length){
        cout << a << endl;
        return;
    }
    all_binary_strings_without_consecutive_1s(a+"0",length,i+1);
    if(a[i]!='1') all_binary_strings_without_consecutive_1s(a+"1",length,i+1);
}

int main(){
    string str = "";
    int n = 4;
    int i = -1;
    // all_binary_strings(str,n);
    all_binary_strings_without_consecutive_1s(str,n,i);
}