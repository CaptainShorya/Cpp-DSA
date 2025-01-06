#include <iostream>
#include <cstring>
using namespace std;

void convertuppercase(char word[],int n){
    for(int i=0; i<n; i++){
        char ch = word[i];
        if(ch >='A' && ch <='Z'){ //Uppercase
            continue;
        }else{ //Lowercase
            word[i] = ch -'a' + 'A';
        }
    }
    cout << word << endl;
}

int main(){
    char word[] = "HeRoo";
    convertuppercase(word, strlen(word)); //Counts before null character so the uppar loop in the function will run only for 5 times.
    return 0;
}