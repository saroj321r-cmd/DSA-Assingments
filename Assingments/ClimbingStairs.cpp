#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;

    cout<<"Enter number of stairs : ";
    cin>>n;

    vector<int> dp(n+1,0);

    // Base Cases
    dp[0]=1;

    if(n>=1)
        dp[1]=1;

    // Fill DP Array
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }

    cout<<"Total Ways = "<<dp[n];

    return 0;
}