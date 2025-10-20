#include <iostream>
#include <string>
using namespace std;

// void removeCharacter(string &s, string str)
// { // TC =O(n^2)
//     if (str.size() == 0)
//         return;
//     if (str[0] != 'a')
//     {
//         s += str[0];
//     }
//     str.erase(0, 1); // O(n) Because erasing from the front of a C++ string means shifting all remaining characters left by one position — every time.
//     removeCharacter(s, str);
// }

// void removeCharacter(string &s, string str)
// { // TC =O(n^2)
//     if (str.size() == 0)
//         return;
//     if (str[0] != 'a')
//     {
//         s += str[0];
//     }
//     str = str.substr(1); //substr() creates a new string copy of length (n-1), (n-2), (n-3)... etc during each recursive step.
//     removeCharacter(s, str);
// }

void removeCharacter(string &s, string str,int idx){ // TC : O(n) Each recursive call does O(1) work.
    if(idx == str.size()) return;
    if(str[idx] != 'a') s += str[idx];
    removeCharacter(s,str,idx+1);
}

int main()
{
    string str = "Raghav Garg";
    string s = "";
    removeCharacter(s, str, 0);
    cout << s << endl;
    return 0;
}