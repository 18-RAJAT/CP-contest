#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int dp[4]={0,0,0,0},ndp[4]={0,0,0,0};
    dp[0]=1;
    for(int i=0;i<n;++i)
    {
        fill(ndp,ndp+4,0);
        if(dp[0]>0)
        {
            if(a[i]=='.' && b[i]=='.')
            {
                ndp[0]+=dp[0];
                if(i+1<n && a[i+1]=='.' && b[i+1]=='.')ndp[3]+=dp[0];
            }
            else if(a[i]=='.' && b[i]=='#')
            {
                if(i+1<n && a[i+1]=='.')ndp[1]+=dp[0];
            }
            else if(a[i]=='#' && b[i]=='.')
            {
                if(i+1<n && b[i+1]=='.')ndp[2]+=dp[0];
            }
            else ndp[0]+=dp[0];
        }
        if(dp[1]>0)
        {
            if(b[i]=='.' && i+1<n && b[i+1]=='.')ndp[2]+=dp[1];
            else if(b[i]=='#')ndp[0]+=dp[1];
        }
        if(dp[2]>0)
        {
            if(a[i]=='.' && i+1<n && a[i+1]=='.')ndp[1]+=dp[2];
            else if(a[i]=='#')ndp[0]+=dp[2];
        }
        if(dp[3]>0)ndp[0]+=dp[3];
        for(int j=0;j<4;++j)dp[j]=min(ndp[j],2LL);
    }
    if(dp[0]==0)cout<<"None"<<endl;
    else if(dp[0]==1)cout<<"Unique"<<endl;
    else cout<<"Multiple"<<endl;
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