#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)cin>>a[i][j];
        sort(a[i].begin(),a[i].end());
    }
    vector<int>ar(n);
    for(int i=0;i<n;++i)ar[i]=i;
    sort(ar.begin(),ar.end(),[&](int x,int y)
    {
        return a[x]<a[y];
    });
    int ok=1;
    for(int i=0;i<n-1 && ok;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(a[ar[i+1]][j]<=a[ar[i]][j])
            {
                ok=0;
                break;
            }
        }
    }
    for(int i=0;i<m-1 && ok;++i)
    {
        if(a[ar[0]][i+1]<=a[ar[n-1]][i])ok=0;
    }
    if(!ok)cout<<-1<<endl;
    else
    {
        for(int i=0;i<n;++i)cout<<ar[i]+1<<(i==n-1?"\n":" ");
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