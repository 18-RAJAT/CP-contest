#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            int stable=0;
            if(i+1<n)stable=max(stable,a[i+1][j]);
            if(j+1<m)stable=max(stable,a[i][j+1]);
            if(i-1>=0)stable=max(stable,a[i-1][j]);
            if(j-1>=0)stable=max(stable,a[i][j-1]);
            a[i][j]=min(a[i][j],stable);
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cout<<a[i][j]<<" \n"[j==m-1];
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