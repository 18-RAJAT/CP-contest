#include<bits/stdc++.h>
using namespace std;
#define int long long
int Gcd(int a,int b)
{
    if(b==0)return a;
    return Gcd(b,a%b);
}
vector<int>compute(int n,int k)
{
    vector<int>ans(n+1,0);
    for(int i=1;i<=n;++i)
    {
        ans[i]=Gcd(i,k);
    }
    return ans;
}
void sol()
{
    int n,a,b;
    cin>>n>>a>>b;
    vector<int>A=compute(n,a),B=compute(n,b);
    vector<int>dp(n+1,0);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            int cost=A[i]+B[j];
            if(i==1 && j==1)dp[j]=cost;
            else if(i==1)dp[j]=dp[j-1]+cost;
            else if(j==1)dp[j]=dp[j]+cost;
            else dp[j]=min(dp[j],dp[j-1])+cost;
        }
    }
    cout<<dp[n]<<endl;
}
signed main()
{
    sol();
    return 0;
}