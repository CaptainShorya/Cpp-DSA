#include <iostream>

using namespace std;

bool palindrome(string str, int st, int end){
    if(st > end) return true;
    char ch = str[st];
    char dh = str[end];
    if(ch != dh) return false;
    else return palindrome(str,st+1,end-1);
}

int main(){
    string str = "raceca";
    cout << palindrome(str,0,str.size()-1);
}