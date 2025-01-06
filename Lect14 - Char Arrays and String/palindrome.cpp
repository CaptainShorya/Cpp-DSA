#include <iostream>
#include <cstring>
using namespace std;

bool isPlaindrome(char word[], int n){
    int st=0, en=n-1;
    while(st < en){
        if(word[st] != word[en]){
            cout << "Not valid Palindrome";
            return false;
        }
        st++,en--;
    }
    cout << "Valid Palindrome";
    return true;
}

int main(){
    char word[] = "racecar";
    isPlaindrome(word,strlen(word));
    return 0;
}