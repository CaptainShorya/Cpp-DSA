#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string str1, string str2){
    if(str1.length() != str2.length()){
        cout << "Not valid Anagram" << endl;
        return  false;
    }
    int count[26] = {0}; //Initialize with 0
    for(int i=0; i<str1.length(); i++){
        int idx = str1[i] - 'a';
        count[idx]++;
    }
    
    for(int j=0; j<str2.length(); j++){
        int idx = str2[j] - 'a';
        if(count[idx] == 0){
            cout << "Not valid Anagram\n" << endl;
            return  false;
        }
        count[idx]--;
    }
    cout << "Valid Anagram" << endl;
    return true;
}


int main(){
    string str1 = "anagram";
    string str2 = "nagaram";
    isAnagram(str1,str2);

    //Operators 
    string str3 = "Cat";
    string str4 = "Dog";

    //These operation are not possible to do with char array That is why string is more efficient in programming.
    cout << (str3 == str4) << endl; //false
    cout << (str3 != str4) << endl; //true 
    cout << (str3 < str4) << endl; ////true
    return 0;
}