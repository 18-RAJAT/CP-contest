#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int h=(n+1)/2;
    vector<int>R;
    R.reserve(n);
    for(int i=1;i<=n;++i)
    {
        if(i==h)continue;
        R.push_back(i);
    }
    R.push_back(h);
    vector<vector<int>>grid(n,vector<int>(n));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            grid[i][j]=R[(j+i)%n];
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<grid[i][j]<<(j+1<n?" ":"\n");
        }
    }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}