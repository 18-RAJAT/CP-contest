#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=2e5+10;
int n,m;
map<array<int,3>,int>dp;
int a[MAX],b[MAX];

int recur(int i,int j,int k)
{
    if(i==n+m+1)return 0;
    if(dp.count({i,j,k}))return dp[{i,j,k}];
    return(((a[i]>b[i] && j) || k==0)?dp[{i,j,k}]=a[i]+recur(i+1,j-1,k):dp[{i,j,k}]=b[i]+recur(i+1,j,k-1));
}
void sol()
{
    cin>>n>>m;
    for(int i=0;i<=n+m;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<=n+m;++i)
    {
        cin>>b[i];
    }
    dp.clear();
    int ans=0,j=n,k=m;
    for(int i=0;i<=n+m;++i)
    {
    	cout<<ans+recur(i+1,j,k)<<(i==n+m?" \n":" ");
        if((j && b[i]<a[i]) || k==0)
        {
            j--,ans+=a[i];
        }
        else
        {
            k--,ans +=b[i];
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