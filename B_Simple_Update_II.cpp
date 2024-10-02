#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int prefix[n],suffix[n];
    fill(prefix,prefix+n,0),fill(suffix,suffix+n,0);
    int count=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='1')count++;
        prefix[i]=count;
    }
    count=0;
    for(int i=n-1;i>=0;--i)
    {
        if(s[i]=='1')count++;
        suffix[i]=count;
    }
    int Ind1=0,Ind2=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0')Ind2=i;
    }
    for(int i=n-1;i>=0;--i)
    {
        if(s[i]=='0')Ind1=i;
    }
    int dp[n/2+1];
    fill(dp,dp+n/2+1,0);
    for(int i=1;i<=n/2;++i)
    {
        if(prefix[n-1]>=(n-i))dp[i]=0;
        else
        {
            int prev=Ind1,curr=Ind2;
            curr-=i;
            dp[i]=(curr-prev+i)/i;
        }
    }

    for(int i=1;i<=n/2;++i)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
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
