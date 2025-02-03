#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(n));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)cin>>a[i][j];
    }
    vector<int>suf(n,0);
    for(int i=0;i<n;++i)
    {
        int c=0;
        for(int j=n-1;~j;--j)
        {
            if(a[i][j]==1)c++;
            else break;
        }
        suf[i]=c;
    }
    sort(suf.begin(),suf.end());
    int ans=0;
    for(int i=0;i<n;++i)if(suf[i]>=ans)ans++;
    cout<<ans<<endl;
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