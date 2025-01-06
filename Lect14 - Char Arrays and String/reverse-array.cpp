#include <iostream>
#include <cstring>
using namespace std;

void reverseArray(char word[], int n){
    int st=0, en=n-1;
    while(st < en){
        swap(word[st],word[en]);
        st++;
        en--;
    }
    cout << "Reverse : " << word << endl;
}

int main(){
    char word[] = {'c','o','d','e','\0'};
    reverseArray(word,strlen(word));
    return 0;

}