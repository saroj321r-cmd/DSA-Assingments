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
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    if(n == 0)
    {
        cout << "Array is empty.";
        return 0;
    }

    int maxProd = arr[0];
    int minProd = arr[0];
    int ans = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] < 0)
            swap(maxProd, minProd);

        maxProd = max(arr[i], arr[i] * maxProd);
        minProd = min(arr[i], arr[i] * minProd);

        ans = max(ans, maxProd);
    }

    cout << "Maximum Product = " << ans;

    return 0;
}