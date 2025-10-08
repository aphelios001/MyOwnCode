#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> ans(n + 1, 0);
    stack<int> stk;
    for(int i = 1; i <= n; i++)
    {
        while(!stk.empty() && a[i] > a[stk.top()])
        {
            ans[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    for(int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}