#include <iostream>
#include <stack>
using namespace std;

int priority(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else
        return 2; // *,/
}

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
    string s = "2+6*4/8-3"; // Infix Expression

    // We need 2 stacks -> one for values and one for operators
    stack<int> values;
    stack<char> op;

    for (int i = 0; i < s.length(); i++)
    {

        // Check if s[i] is a digit
        if (s[i] >= 48 && s[i] <= 57)
        { // In C++, if we compare char with a value,then it automatically compares its ascii value with the given number
            // Since s[i] represents character and pushing number is our requirement
            values.push(s[i] - 48);
        }
        // Check if s[i] is a symbol -> *,/,-,+
        else
        {
            if (op.size() == 0 || priority(s[i]) > priority(op.top()))
            {
                op.push(s[i]);
            }
            else
            {
                // priority(s[i]) <= priority(op.top())
                // I have to do val1 op val2
                while (op.size() > 0 && priority(s[i]) <= priority(op.top()))
                {
                    char ch = op.top();
                    op.pop();
                    int val2 = values.top();
                    values.pop();
                    int val1 = values.top();
                    values.pop();

                    // Create a solver function to evaluate the numeric result
                    int ans = solve(val1, val2, ch);
                    values.push(ans);
                }
                op.push(s[i]); // Push upcoming operator
            }
        }
    }
    // The operator stack can have values.
    // So make it empty
    while (op.size() > 0)
    {

        // work
        char ch = op.top();
        op.pop();
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        int ans = solve(val1, val2, ch);
        values.push(ans);
    }
    cout << values.top() << endl;
}