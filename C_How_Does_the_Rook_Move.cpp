#include<bits/stdc++.h>
using namespace std;
#define int long long
int Visited[3000005],Dp[3000005];
void sol()
{
    int n,k;
    cin>>n>>k;
    int ways=0,moves;
    for(int i=1;i<=n;++i)Visited[i]=0;
    for(int i=1;i<=k;++i)
    {
        int x,y;
        cin>>x>>y;
        Visited[x]=Visited[y]=1;
    }
    for(int i=1;i<=n;++i)
    {
        if(Visited[i])
        {
            continue;
        }
        else
        {
            ways++;
        }
    }
    Dp[0]=1;
    for(int i=1;i<=ways;++i)
    {
        // for(int j=1;j<=k;++j)
        // {
        //     if(j>=i)
        //     {
        //         Dp[j]+=Dp[j-i];
        //         Dp[j]%=1000000007;
        //     }
        // }
        Dp[i]=Dp[i-1];//+i;
        if(i>=2)
        {
            moves=2*(i-1)%1000000007;
            Dp[i]=(Dp[i]+Dp[i-2]*moves%1000000007)%1000000007;
        }
    }
    cout<<Dp[ways]<<endl;
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