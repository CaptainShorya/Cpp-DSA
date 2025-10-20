#include <iostream>
#include <string>
using namespace std;

// void subset(string str,string s){ //We are creating a new string everytime
//     if(str == ""){
//         cout << s << endl;
//         return;
//     }
//     char ch = str[0];
//     subset(str.substr(1),s+ch);
//     subset(str.substr(1),s);
// }

void subset(string str,string s,int i){ //Use index, to avoid making new string at every step.
    if(str.size() == i){
        cout << s << endl;
        return;
    }
    char ch = str[i];
    subset(str,s+ch,i+1);
    subset(str,s,i+1);
}

int main(){
    string str = "abc";
    subset(str,"",0);
}