#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> dp(n);

    dp[0] = arr[0];

    int ans = dp[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);

        ans = max(ans, dp[i]);
    }

    cout << "Maximum Subarray Sum = " << ans;

    return 0;
}