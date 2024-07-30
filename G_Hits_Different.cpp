#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>dp(10000005);
void sol()
{
    dp[1]=1;
    int l=2,r=3,temp=2,traverse=1,pos=2;
    for(int i=2;i<dp.size();++i)
    {
        if(l==i)
        {
            dp[i]=dp[i-traverse]+i*i,l+=temp;
        }
        else if(r==i)
        {
            dp[i]=dp[i-traverse-1]+i*i;
            r+=temp+1,temp+=1;
            traverse=pos++;
        }
        else
        {
            dp[i]=dp[i-traverse]+dp[i-1-traverse]+i*i-dp[i-2*traverse];
        }
    }
}
signed main()
{
    sol();
    int t;
    cin>>t;
    while(t--)
    {
        dp.clear();
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}