#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[505][505];
int a[1000005],b[1000005];
void sol()
{
    int n,c,d;
    cin>>n>>c>>d;
    int minimum=INT_MAX;
    for(int i=1;i<=n*n;++i)
    {
        cin>>a[i];
        minimum=min(minimum,a[i]);
    }
    //state transition
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            dp[i][j]=0;
        }
    }
    dp[1][1]=minimum;
    int least=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            dp[i+1][j]=dp[i][j]+c;
            dp[i][j+1]=dp[i][j]+d;
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            b[++least]=dp[i][j];
        }
    }
    sort(a+1,a+n*n+1);
    sort(b+1,b+least+1);
    for(int i=1;i<=n*n;++i)
    {
        if(a[i]!=b[i])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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