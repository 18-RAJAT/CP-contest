#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<vector<char>>grid(n,vector<char>(n));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<n;i+=k)
    {
        for(int j=0;j<n;j+=k)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
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