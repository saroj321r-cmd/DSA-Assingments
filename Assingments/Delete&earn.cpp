#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    int maxValue = 0;

    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
        maxValue = max(maxValue, nums[i]);
    }

    vector<int> points(maxValue + 1, 0);

    for(int num : nums)
        points[num] += num;

    vector<int> dp(maxValue + 1, 0);

    dp[0] = 0;

    if(maxValue >= 1)
        dp[1] = points[1];

    for(int i = 2; i <= maxValue; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + points[i]);

    cout << "Maximum Points = " << dp[maxValue];

    return 0;
}