#include<iostream>
#include<climits>
#include <vector>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    dp[1]=abs(v[1]-v[0]);
    for(int i=2;i<n;i++){
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                dp[i]=min(dp[i],dp[i-j]+ abs(v[i]-v[i-j]));
            }
        }
    }
    cout<<dp[n-1];
    return 0 ;
}