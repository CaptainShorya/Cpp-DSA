#include <iostream>
#include <stack>
using namespace std;

int solve(int val1, int val2, char ch)
{
    if (ch == '+')
        return val1 + val2;
    else if (ch == '*')
        return val1 * val2;
    else if (ch == '/')
        return val1 / val2;
    else if (ch == '-')
        return val1 - val2;
}

int main()
{
    string s = "79+4*8/3-"; // Postfix evaluation

    // We need 1 stacks -> one for values
    stack<int> values;

    for (int i = 0; i < s.length(); i++)
    {

        // Check if s[i] is a digit
        if (s[i] >= 48 && s[i] <= 57)
        { // In C++, if we compare char with a value,then it automatically compares character's ascii value with the given number
            // Since s[i] represents character and pushing number is our requirement
            values.push(s[i] - 48);
        }
        // Check if s[i] is a symbol -> *,/,-,+,
        else
        {     //Kaam karo
            int val2 = values.top();
            values.pop();
            int val1 = values.top();
            values.pop();
            int ans = solve(val1, val2, s[i]);
            values.push(ans);
        }
    }
    cout << values.top() << endl;
    cout <<(7+9)*4/8-3 << endl;
    return 0;
}