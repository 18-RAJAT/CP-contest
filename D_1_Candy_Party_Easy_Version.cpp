#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int>mp;
void recur()
{
    int val=1;
    for(int i=0;i<=31;++i)
    {
        mp[val]=i+1;
        val*=2;
    }
}
void sol()
{
    int n;
    cin>>n;
    int sm=0;
    int a[n+1];
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        sm+=a[i];
    }
    if(sm%n!=0)
    {
        cout<<"No"<<endl;
        return;
    }
    sm/=n;
    int dp[50];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;++i)
    {
        int x=a[i],y=abs(a[i]-sm);
        if(y==0)
        {
            continue;
        }
        int c1=0,c2=0;
        while(y%2==0)
        {
            y/=2;
            c1++;
        }
        c2=mp[y+1]-1;
        if(c2==-1)
        {
            cout<<"No"<<endl;
            return;
        }
        c2+=c1;
        if(a[i]<sm)
        {
            dp[c2]++;
            dp[c1]--;
        }
        else
        {
            dp[c1]++;
            dp[c2]--;
        }
    }
    for(int i=0;i<50;++i)
    {
        if(dp[i]!=0)
        {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}
signed main()
{
    recur();
    int t;
    cin>>t;
    while(t--)
    {
    	sol();
    }
    return 0;
}