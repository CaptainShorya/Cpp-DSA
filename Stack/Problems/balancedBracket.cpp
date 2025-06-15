#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool balancedBracket(string s) {
    if (s.length() % 2 != 0) return false;

    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {  
            st.push(s[i]);
        } else { // s[i] == ')'
            if (st.size() == 0) return false;
            else st.pop(); // understood that '(' is there
        }
    }

    if (st.size() == 0) return true;
    else return false;
}

int main() {
    string s = "())()";
    cout << balancedBracket(s);
}
