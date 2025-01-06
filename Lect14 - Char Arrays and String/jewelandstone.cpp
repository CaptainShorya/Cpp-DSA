#include <iostream>
#include <string>
using namespace std;

//Leetcode Problem - 771

int jewelandstone(string jewel,string stones){
    int count = 0;
    for(int i=0; i<jewel.length(); i++){
        for(int j=0; j<stones.length(); j++){
            if(jewel[i] == stones[j]){
                count++;
            }
        }
    }
    return count;
}

int main(){
    string jewel = "zz";
    string stones = "aAAbbbb";
    cout << jewelandstone(jewel,stones) << endl;
}