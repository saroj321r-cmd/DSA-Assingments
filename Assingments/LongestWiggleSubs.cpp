#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    if(n == 0)
    {
        cout << "Length = 0";
        return 0;
    }

    int up = 1;
    int down = 1;

    for(int i = 1; i < n; i++)
    {
        if(nums[i] > nums[i - 1])
            up = down + 1;

        else if(nums[i] < nums[i - 1])
            down = up + 1;
    }

    cout << "Length of Longest Wiggle Subsequence = " << max(up, down);

    return 0;
}