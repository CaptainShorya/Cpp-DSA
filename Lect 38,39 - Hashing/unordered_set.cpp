#include <iostream>
#include <unordered_set>
#include <set>
#include <string>
using namespace std;

int main(){
    unordered_set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(5);
    s.insert(1); //Duplicate values will not stored in the set
    s.insert(1); //Duplicate values will not stored in the set

    cout << s.size() << endl;

    s.erase(3);
    if(s.find(3) != s.end()){
        cout << "3 exists\n";
    }else{
        cout << "3 does not exist\n";
    }

    for(auto el : s){
        cout << el << endl; //Random order m print 
    }

    return 0;
}