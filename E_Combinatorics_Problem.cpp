#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n,x,y,m,k;
    int a[10001];memset(a,0,sizeof(a));

    int dp[10001][6];

    cin>>n>>a[1]>>x>>y>>m>>k;
    dp[1][0]=a[1];

    auto sumQuery=[&](int x,int y)->int
    {
        return x+y;
    };

    auto mulQuery=[&](int x,int y)->int
    {
        return x*y;
    };
    for(int i=2;i<=n;++i)
    {
        a[i]=(a[i-1]*x+y)%m;
        dp[i][0]=a[i];
    }
    for(int j=1;j<=k+1;++j)
    {
        for(int i=1;i<=n;++i)
        {
            dp[i][j]=sumQuery(dp[i-1][j],dp[i][j-1]);
        }
    }
    int res=0;
    int q=n-k+1;
    for(int i=1;i<q;++i)
    {
        int P=dp[i][k+1];
        res^=(P*(i-k-1));
    }
    cout<<res%1000000007<<"\n";
}

int main()
{
    sol();
    return 0;
}