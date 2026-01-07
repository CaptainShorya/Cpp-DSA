#include <iostream>
#include <vector>
using namespace std;

void subset(string ans, string str, bool flag){
    if(str == ""){
        cout << ans << endl;
        return;
    }
    char ch = str[0];
    if(str.length() == 1){
        if(flag == true){
            subset(ans+ch,str.substr(1),true);
        }
        subset(ans,str.substr(1),true);
        return; //So that Neeche ki condition na chle
    }

    //When flag is false meaning Left call run nhi hogi uski

    char dh = str[1];
    if(ch == dh){ // duplicate
        if(flag == true) subset(ans+ch,str.substr(1),true);
        subset(ans,str.substr(1),false);
    }else{ // not duplicate
        if(flag == true)subset(ans+ch,str.substr(1),true);
        subset(ans,str.substr(1),true);
    }
}
//When flag is true, only in that case left call will run.(Imagine this by making recursive tree diagram)
//Otherwise we get duplicate output which causes error.

int main(){
    string str = "aab";
    subset("",str,true);
}