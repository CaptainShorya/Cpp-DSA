#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
int main(){
    // char word[30];
    // cin >> word; //Ignore Whitespaces Eg:Apna College , It will give output - Apna (only)

    // cout << "Your word is : " << word << endl;
    // cout << strlen(word) << endl;

    char sentence[30];
    cin.getline(sentence, 30, '*');

    cout << "Your word is : " << sentence << endl;
    cout << strlen(sentence) << endl;
    return 0;
}