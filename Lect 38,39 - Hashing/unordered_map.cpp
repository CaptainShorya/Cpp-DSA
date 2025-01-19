#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
using namespace std;

int main(){
    unordered_map <string,int> m;

    m["China"] = 150; //Interanlly the string value (ie China) get converted into integer value using a hash function(Studied earlier)
    m["India"] = 150;
    m["US"] = 50;
    m["Nepal"] = 20;

    m["Nepal"] = 200; //it will override the value 20 by 200 and didn't create new Nepal (key) bcz keys are unique 

    for(pair<string,int> country : m){
        cout << country.first << "," << country.second << endl;
    }

    //count -> check whether an key value pair exist or not, if exist return 1 otherwise 0
    if(m.count("Nepal") == 1){
        cout << "Nepal exists" << endl;
    }else{
        cout << "Nepal doesn't exist" << endl;
    }

    m.erase("Nepal"); //remove the particular entered key value pair;
    return 0;
}