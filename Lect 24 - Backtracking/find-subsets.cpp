#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Find All possible subsets of a string

void subsets(string str, string substring){
    //Base Case
    if(str.size() == 0){
        cout << substring << endl;
        return;
    }
    char ch = str[0];
    int n = str.size();

    subsets(str.substr(1,n-1),substring+ch); //Yes Choice 

    subsets(str.substr(1,n-1),substring); // No Choice 

    //substr(kaha se start kre,kitni length ka element chaiye)
}

int main(){
    string str = "abc";
    string substring = "";
    int sizeofStr = str.size();

    subsets(str,substring);
}