#include<iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> dp(n);
    dp[0]=v[0];
    int maxsum=v[0];
    for(int i = 0;i<n;i++){
        dp[i]=max(v[i],dp[i-1]+v[i]);
        maxsum = max(maxsum,dp[i]);
    }
    cout<<maxsum<<endl;
    return 0 ;
}