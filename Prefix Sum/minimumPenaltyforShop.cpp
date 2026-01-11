#include <iostream>
#include <vector>
using namespace std;

// Minimum Penalty for A Shop (Prefix Sum Problem)

// Core Concept ->  know that penalty occur only when **N occur before shop** is closed and **Y occur when shop is open** which means  => 
//Penalty = prefix Sum of 'N' + suffix Sum of 'Y'

int main()
{
    string customers = "YYNY";
    int n = customers.length();
    int shop = 0;
    int earliest_hour = 0;
    int min_penalty = INT32_MAX;
    vector<int> penalty(n + 1, 0);
    vector<int> count_N(n + 1, 0);
    vector<int> count_Y(n + 1, 0);

    // prefix Sum of X
    for (int i = 1; i <= n; i++)
    {
        if (customers[i - 1] == 'N')
            count_N[i] = count_N[i - 1] + 1;
        else
            count_N[i] = count_N[i - 1];
    }
    // suffix sum of Y
    for (int i = n - 1; i >= 0; i--)
    {
        if (customers[i] == 'Y')
            count_Y[i] = count_Y[i + 1] + 1;
        else
            count_Y[i] = count_Y[i + 1];
    }
    while (shop <= n)
    {
        int curr_penalty = count_N[shop] + count_Y[shop];
        if (curr_penalty < min_penalty)
        {
            min_penalty = curr_penalty;
            earliest_hour = shop;
        }
        shop++;
    }
    cout << earliest_hour << endl;
}