#include <iostream>
using namespace std;

//Remove Duplicates from String -> Can be resolved by Hashmap
//Use this approach 
void removeDuplicate(string str, string ans, int i, bool map[26]){

    if(i == str.size()){
        cout << "ans = " << ans << endl; 
        return;
    }

    char ch = str[i];
    int mapIdx = (int)(ch - 'a'); // 'a' -> 0 , 'b' -> 1

    if(map[mapIdx]){ //duplicate
        removeDuplicate(str,ans,i+1,map);
    }else{ // not duplicate
        map[mapIdx] = true;
        removeDuplicate(str,ans+str[i],i+1,map);
    }

}

//No need of using i variable in it, loop operates backward
void removeDuplicateBack(string str, string ans, bool map[26]){

    if(str.size() == 0){
        cout << "ans = " << ans << endl;  
        return;
    }

    int n = str.size();
    char ch = str[n-1];
    int mapIdx = (int)(ch - 'a'); // 'a' -> 0 , 'b' -> 1
    str = str.substr(0,n-1);

    if(map[mapIdx]){ //duplicate
        removeDuplicateBack(str,ans, map);
    }else{ // not duplicate
        map[mapIdx] = true;
        removeDuplicateBack(str,ch+ans, map);
    }

}

int main() {
    string str = "appnnacollege";
    string ans = "";
    int i = 0;
    bool map[26] = {false};


    removeDuplicate(str,ans,i,map); // apncolge

    // removeDuplicateBack(str,ans,map); // pnacolge

    return 0;
}