#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of coin denominations: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin values:\n";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int amount;
    cout << "Enter target amount: ";
    cin >> amount;

    const int INF = 1e9;

    vector<int> dp(amount + 1, INF);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (i - coin >= 0)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[amount] == INF)
        cout << "It is not possible to form the amount.\n";
    else
        cout << "Minimum Coins Required = " << dp[amount];

    return 0;
}