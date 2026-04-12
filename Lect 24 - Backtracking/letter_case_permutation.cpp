#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int n;
    vector<string> result;
    //BackTracking Approach

    void letterPermutations(string s, string& str, int index){
        if(str.length() == s.length()){ // Base case
            result.push_back(str);
            return;
        }
        if(isdigit(s[index])){
            str += s[index];
            letterPermutations(s,str,index+1);
            str.pop_back();
        }
        else{
            str += (char)tolower(s[index]);
            letterPermutations(s,str,index+1);
            str.pop_back();
            str += (char)toupper(s[index]);
            letterPermutations(s,str,index+1);
            str.pop_back();
        }
        
    }
    vector<string> letterCasePermutation(string s) {
        n = s.length();
        int index = 0;
        string str = "";
        letterPermutations(s,str,index);
        return result;
    }
};

class Solution {
public:
    int n;
    vector<string> result;

    void letterPermutations(string s, int index){
        if(index == s.length() ){ // Base case
            result.push_back(s);
            return;
        }
        if(isdigit(s[index])){
            letterPermutations(s,index+1); // Skip digits by moving down in rec tree
        }
        else{
            string left = s.substr(0,index); // Left string
            string right = s.substr(index+1); // Right string
            letterPermutations(left+s[index]+right,index+1); // No change
            if(isupper(s[index])) letterPermutations(left+(char)tolower(s[index])+right,index+1);
            else letterPermutations(left+(char)toupper(s[index])+right,index+1); // Change s[i]
        }
        
    }
    vector<string> letterCasePermutation(string s) {
        n = s.length();
        int index = 0;
        letterPermutations(s,index);
        return result;
    }
};