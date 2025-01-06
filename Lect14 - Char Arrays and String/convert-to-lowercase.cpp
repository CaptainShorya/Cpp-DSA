#include <iostream>
#include <cstring>
using namespace std;

void convertlowercase(char word[], int n){
    for(int i=0; i<n; i++){
        char ch = word[i];
        if(ch>='a' && ch<='z'){
            continue;
        }else{
            word[i] = ch - 'A' + 'a';
        }
    }
    cout << word << endl;
}

int main(){
    char word[] = "AppLE"; //Character Array - 'A','p','p','L','E','\0'
    convertlowercase(word, strlen(word));
    return 0;
}