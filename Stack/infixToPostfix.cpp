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

string solve(string val1, string val2, char ch)
{
    return val1+val2+ch; // Rest all resembles with the infixtoPrefix code.
}

int main()
{
    string s = "(7+9)*4/8-3"; // Infix Expression

    // We need 2 stacks -> one for values and one for operators
    stack<string> values;
    stack<char> op;

    for (int i = 0; i < s.length(); i++)
    {

        // Check if s[i] is a digit
        if (s[i] >= 48 && s[i] <= 57)
        { // In C++, if we compare char with a value,then it automatically compares character's ascii value with the given number
            // Since s[i] represents character and pushing number is our requirement
            values.push(to_string(s[i] - 48));
        }
        // Check if s[i] is a symbol -> *,/,-,+,(,)
        else
        {
            // Condition 1
            if (op.size() == 0)
                op.push(s[i]);
            // Condition 2
            else if (s[i] == '(')
                op.push(s[i]);
            // Condition 3
            else if (op.top() == '(')
                op.push(s[i]);
            // Condition 4 // can't do 5 before 4 as we have not set priority for '(' OR ')'
            else if (s[i] == ')')
            {
                while (op.top() != '(')
                {
                    char ch = op.top();
                    op.pop();
                    string val2 = values.top();
                    values.pop();
                    string val1 = values.top();
                    values.pop();

                    // Create a solver function to evaluate the numeric result
                    string ans = solve(val1, val2, ch);
                    values.push(ans);
                }
                op.pop(); // Opening bracket removed
            }
            // Condition 5
            else if (priority(s[i]) > priority(op.top()))
                op.push(s[i]);
            // Condition 6
            else
            {
                // priority(s[i]) <= priority(op.top())
                // I have to do val1 op val2
                while (op.size() > 0 && priority(s[i]) <= priority(op.top()))
                {
                    char ch = op.top();
                    op.pop();
                    string val2 = values.top();
                    values.pop();
                    string val1 = values.top();
                    values.pop();

                    // Create a solver function to evaluate the numeric result
                    string ans = solve(val1, val2, ch);
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
        string val2 = values.top();
        values.pop();
        string val1 = values.top();
        values.pop();
        string ans = solve(val1, val2, ch);
        values.push(ans);
    }
    cout << values.top() << endl;
    return 0;
}