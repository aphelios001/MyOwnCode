#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 30, W = 30;
    vector<int> dp(n + 1, 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = W; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], d[j - w[i]] + v[i]);
        }
    }

}