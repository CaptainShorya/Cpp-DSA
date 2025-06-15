#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string removeConsecutiveDuplicates(string s){
    if(s.length() == 0) return "";
    stack<char> st;
    st.push(s[0]);
    for(int i=1; i<s.length(); i++){
        if(st.top() != s[i]) st.push(s[i]);
    }
    s = "";
    while(st.size() > 0){
        s += st.top();
        st.pop();
    }
    reverse(s.begin(),s.end());
    return s;
}

int main(){
    string s = "aaabbcddaabffg";
    cout << "Original String : ";
    cout << s << endl;
    s = removeConsecutiveDuplicates(s);
    cout << "Remove Duplicates : ";
    cout << s << endl;
}