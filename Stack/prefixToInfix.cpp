#include <iostream>
#include <stack>
using namespace std;

string solve(string val1, string val2, char ch)
{
    return val1+ch+val2;
}

int main()
{
    string s = "-/*+79483"; // Prefix expression 

    // We need 1 stacks -> one for values
    stack<string> values;

    for (int i = s.length()-1; i >=0 ; i--)
    {

        // Check if s[i] is a digit
        if (s[i] >= 48 && s[i] <= 57)
        { // In C++, if we compare char with a value,then it automatically compares character's ascii value with the given number
            // Since s[i] represents character and pushing number is our requirement
            values.push(to_string(s[i] - 48));
        }
        // Check if s[i] is a symbol -> *,/,-,+,
        else
        {     //Kaam karo
            string val1 = values.top();
            values.pop();
            string val2 = values.top();
            values.pop();
            string ans = solve(val1, val2, s[i]);
            values.push(ans);
        }
    }
    cout << values.top() << endl;  //Infix Expression
    return 0;
}