#include <iostream>
#include <string>
using namespace std;

string compressedString(string word) {
        string comp = "";
        for (int i = 0; i < word.length(); i++) {
            if (word[i] != word[i + 1]){
                comp = comp + "1" + word[i];
            }else{
                int count = 1;
                while(i+1 <word.length() && word[i] == word[i + 1] &&  count < 9){
                    count = count + 1;
                    i++;
                }
                comp = comp + to_string(count) + word[i-1];
            }
        }
        return comp;
    }

int main(){
    string word = "1010";
    // cout << compressedString(word) << endl;
    cout << word[0] << endl;
    cout << word[0] == "1";
    return 0;
}


//Editorial Solution
// class Solution {
// public:
//     string compressedString(string word) {
//         string comp = "";

//         // pos tracks our position in the input string
//         int pos = 0;

//         // Process until we reach end of string
//         while (pos < word.length()) {
//             int consecutiveCount = 0;

//             char currentChar = word[pos];

//             // Count consecutive occurrences (maximum 9)
//             while (pos < word.length() && consecutiveCount < 9 &&
//                    word[pos] == currentChar) {
//                 consecutiveCount++;
//                 pos++;
//             }

//             // Append count followed by character to result
//             comp += to_string(consecutiveCount) + currentChar;
//         }

//         return comp;
//     }
// };



// string comp = "";
//         for (int i = 0; i < word.length(); i++) {
//             if (i+1 >=word.length() || word[i] != word[i + 1]) {
//                 comp = comp + "1" + word[i];
//             } else {
//                 int count = 1;
//                 while (i + 1 < word.length() && word[i] == word[i + 1] &&
//                        count < 9) {
//                     count = count + 1;
//                     i++;
//                 }
//                 comp = comp + to_string(count) + word[i];
//             }
//         }
//         return comp;