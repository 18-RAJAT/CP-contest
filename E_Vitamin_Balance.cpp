#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>>t1,t2,t3;
    for(int i=0;i<n;++i)
    {
        int v,a,c;
        cin>>v>>a>>c;
        if(v==1)t1.push_back({a,c});
        else if(v==2)t2.push_back({a,c});
        else t3.push_back({a,c});
    }
    auto pre=[&](vector<pair<int,int>>&ar)
    {
        vector<int>dp(x+1,-1e18);
        dp[0]=0;
        for(auto& it:ar)
        {
            int a=it.first,c=it.second;
            for(int i=x;i>=c;--i)
            {
                dp[i]=max(dp[i],dp[i-c]+a);
            }
        }
        return dp;
    };
    vector<int>dp1=pre(t1),dp2=pre(t2),dp3=pre(t3);
    int s1=0,s2=0,s3=0;
    for(auto& it:t1)s1+=it.first;
    for(auto& it:t2)s2+=it.first;
    for(auto& it:t3)s3+=it.first;
    int up=min({s1,s2,s3});
    int l=0,r=up,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2,Mx1=1e18,Mx2=1e18,Mx3=1e18;
        for(int i=0;i<=x;++i)if(dp1[i]>=mid){Mx1=i;break;}
        for(int i=0;i<=x;++i)if(dp2[i]>=mid){Mx2=i;break;}
        for(int i=0;i<=x;++i)if(dp3[i]>=mid){Mx3=i;break;}
        if(Mx1==1e18 || Mx2==1e18 || Mx3==1e18){r=mid-1;continue;}
        (Mx1+Mx2+Mx3<=x)?(ans=mid,l=mid+1):(r=mid-1);
    }
    cout<<ans<<endl;
}
signed main()
{
    sol(); 
    return 0;
}