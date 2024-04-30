#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<pair<array<int,2>,int>>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first[0];
        a[i].second=i;
    }
    sort(a.begin(),a.end());
    stack<int>s;
    int cnt=0;
    for(int i=0;i<2*n;++i)
    {
        char dp[2*n];
        cin>>dp[i];
        if(dp[i]=='0')
        {
            cout<<a[cnt].second+1<<" ";
            s.push(a[cnt++].second);
        }
        else
        {
            cout<<s.top()+1<<" ";
            s.pop();
        }
    }
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}