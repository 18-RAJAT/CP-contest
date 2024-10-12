#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Dsu
{
    vector<int>parent;
    Dsu(int n)
    {
        parent=vector<int>(n,-1);
    }
    int Get(int x)
    {
        return parent[x]<0?x:parent[x]=Get(parent[x]);
    }
    bool Unite(int x,int y)
    {
        x=Get(x),y=Get(y);
        if(x==y) return false;
        if(parent[x]>parent[y])swap(x,y);
        parent[x]+=parent[y];
        parent[y]=x;
        return true;
    }
};
void sol()
{
    int n,m;
    cin>>n>>m;
    int dots=11;
    vector<vector<int>>Dp(n,vector<int>(dots));
    for(int i=0;i<m;++i)
    {
        int a,d,k;
        cin>>a>>d>>k;
        a--;
        Dp[a][d]=max(Dp[a][d],k);
    }
    Dsu dsu(n);
    for(int i=0;i<n;++i)
    {
        int j=1;
        while(i+j<n && j<dots)
        {
            if(Dp[i][j]>=1)dsu.Unite(i,i+j);
            Dp[i+j][j]=max(Dp[i+j][j],Dp[i][j]-1);
            j++;
        }
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(dsu.Get(i)==i)ans++;
    }
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