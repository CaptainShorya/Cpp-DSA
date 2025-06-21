#include <iostream>
#include <stack>
using namespace std;

string solve(string val1, string val2, char ch)
{
    return ch+val1+val2;
}

int main()
{
    string s = "79+4*8/3-"; // Postfix expression 

    // We need 1 stacks -> one for values
    stack<string> values;

    for (int i = 0; i < s.length(); i++)
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
            string val2 = values.top();
            values.pop();
            string val1 = values.top();
            values.pop();
            string ans = solve(val1, val2, s[i]);
            values.push(ans);
        }
    }
    cout << values.top() << endl; //Prefix Expression
    return 0;
}