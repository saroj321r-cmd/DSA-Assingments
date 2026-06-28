#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;

    cout << "Enter n : ";
    cin >> n;

    // Invalid input
    if (n < 0)
    {
        cout << "Invalid Input";
        return 0;
    }

    // DP Array
    vector<int> dp(n + 1, 0);

    dp[0] = 0;

    if (n >= 1)
        dp[1] = 1;

    // Fill DP Array
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << "Fibonacci Number = " << dp[n];

    return 0;
}