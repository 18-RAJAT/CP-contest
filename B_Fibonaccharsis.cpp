#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[100010];
void sol()
{
    int n,k;
    cin>>n>>k;
    int ans=0;
    if(k>28)
    {
        cout<<0<<"\n";
        return;
    }
    int x=dp[k-2];
    int y=dp[k-1];

    for(int i=0;i<=n;++i)
    {
        int delta=n-x*i;
        if(delta%y==0 && delta/y>=i)
        {
            ans++;
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    dp[1]=1,dp[2]=1;
    for(int i=3;i<28;++i)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
	int t;
	cin>>t;
	while(t--)
	{
        sol();
    }
}