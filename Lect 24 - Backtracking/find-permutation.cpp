#include <iostream>
using namespace std;

//Find and print all the permutations(arrangement) of a given string.

//A permutation of a string is a rearrangement of its characters in a specific order. The number of permutations a string can have is determined by its length. 
//Example -> The permutations of the string "ABC" are "ABC", "ACB", "BAC", "BCA", "CBA", and "CAB".

void generatePermutations(string str, string permStr){
    //Base Case
    if(str.size() == 0){
        cout << permStr << " ";
        return;
    }
    for(int i=0; i<str.size(); i++){
        string remainingStr = str.substr(0,i) + str.substr(i+1);
        generatePermutations(remainingStr,permStr+str[i]); //ith character choice to add in permutation
    }
}

int main(){
    string str = "abc";
    string permStr = "";

    generatePermutations(str,permStr);
    return 0;
}