#include <iostream>
#include <vector>
using namespace std;

//Find all permutation of an string given all the elements of the string are unique.

void permutations(string str, string empty){
    if(str.size() == 0){
        cout << empty << endl;
        return;
    }
    for(int i=0; i<str.size(); i++){
        char ch = str[i];

        //Method 1 -> creating new string  , TC = O(n!)
        // string new_str = "";
        // for(int j=0;j<str.size(); j++){
        //     if(str[j] != ch) new_str = new_str+str[j];
        // }
        // permutations(new_str,empty+ch);

        //Method 2 -> substr function  , TC = O(n*n!)
        permutations(str.substr(0,i)+str.substr(i+1),empty+ch);
        // abcde , i=2 -> str.substr(0,2)+str.substr(3,5-2-1)
       
    }
}

int main(){
    string str = "abc";
    permutations(str,"");
}