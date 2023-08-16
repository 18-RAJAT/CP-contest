#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int ans=2*n-m+1;
    vector<vector<int>>a(m);
    for(int i=0;i<m;i++)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int x;
            cin>>x;
            a[i].push_back(x);
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            if(a[i][j]==j+1)
            {
                ans-=2;
            }
        }
    }
    cout<<ans<<"\n";
}
signed main()
{
    sol();
}