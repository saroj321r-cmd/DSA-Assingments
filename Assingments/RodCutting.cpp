#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;

    cout << "Enter Rod Length : ";
    cin >> n;

    vector<int> price(n + 1);

    cout << "Enter Prices:\n";

    for (int i = 1; i <= n; i++)
        cin >> price[i];

    vector<int> dp(n + 1, 0);

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int cut = 1; cut <= i; cut++)
        {
            dp[i] = max(dp[i], price[cut] + dp[i - cut]);
        }
    }

    cout << "Maximum Profit = " << dp[n];

    return 0;
}