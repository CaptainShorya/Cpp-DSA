#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

//Valid Anagram

bool validAnagrams(string s, string t){
    if(s.size() != t.size()) return false;

    //s<char,int> 
    unordered_map<char,int> mpp;
    for(int i=0; i<s.length(); i++){
        if(mpp.count(s[i]) == 0){
            mpp[s[i]] = 1;
        }else{
            mpp[s[i]]++;
        }
    }
    //to look for t's character in map
    for(int i=0; i<t.length(); i++){
        if(mpp.count(t[i])){
            mpp[t[i]]--;
            if(mpp[t[i]] == 0){
                mpp.erase(t[i]);
            }
        }else{
            return false;
        }
    }
    
    return mpp.size() == 0;

}

int main(){
    string s = "tulip";
    string t = "lipid";

    cout << validAnagrams(s,t)<< endl;
    return 0;
}