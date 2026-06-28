#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, K, S;

    cout << "Enter number of dice: ";
    cin >> N;

    cout << "Enter number of faces: ";
    cin >> K;

    cout << "Enter target sum: ";
    cin >> S;

    vector<int> dp(S + 1, 0);
    dp[0] = 1;

    for(int dice = 1; dice <= N; dice++)
    {
        vector<int> temp(S + 1, 0);

        for(int sum = 0; sum <= S; sum++)
        {
            if(dp[sum] == 0)
                continue;

            for(int face = 1; face <= K; face++)
            {
                if(sum + face <= S)
                    temp[sum + face] += dp[sum];
            }
        }

        dp = temp;
    }

    cout << "Number of Ways = " << dp[S];

    return 0;
}