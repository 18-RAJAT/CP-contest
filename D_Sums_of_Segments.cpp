#include<bits/stdc++.h>
using namespace std;
#define int long long
array<int,2>segments(int pos,vector<int>&start,int n)
{
    int row=lower_bound(start.begin(),start.end(),pos+1)-start.begin()-1;
    int col=row+(pos-start[row]);
    return{row,col};
}
signed main()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n),c(n);
    for(int i=0;i<n;++i)cin>>a[i];
    b[0]=a[0];
    for(int i=1;i<n;++i)b[i]=b[i-1]+a[i];
    c[0]=b[0];
    for(int i=1;i<n;++i)c[i]=c[i-1]+b[i];
    vector<int>dp(n),ndp(n);
    for(int i=0;i<n;++i)
    {
        if(i==0)
        {
            dp[i]=c[n-1];
        }
        else
        {
            dp[i]=c[n-1]-c[i-1]-((n-i)*b[i-1]);
        }
    }
    ndp[0]=dp[0];
    for(int i=1;i<n;++i)ndp[i]=ndp[i-1]+dp[i];
    vector<int>ans(n+1,0);
    for(int i=1;i<=n;++i)ans[i]=ans[i-1]+(n-i+1);
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        array<int,2>seg1=segments(l,ans,n);
        array<int,2>seg2=segments(r,ans,n);
        int r1=seg1[0],c1=seg1[1],r2=seg2[0],c2=seg2[1];
        int res=0;
        if(r1==r2)
        {
            res=(c[c2]-(c1>=1?c[c1-1]:0));
            if(r1>=1)
            {
                res-=((c2-c1+1)*b[r1-1]);
            }
        }
        else
        {
            int temp=(c[n-1]-(c1>=1?c[c1-1]:0)),pre=0,sums=0;
            if(r1>=1)
            {
                temp-=((n-c1)*b[r1-1]);
            }
            if(r2-1>=r1+1)pre=ndp[r2-1]-(r1>=0?ndp[r1]:0);
            sums=(c[c2]-(r2>=1?c[r2-1]:0));
            if(r2>=1)sums-=((c2-r2+1)*b[r2-1]);
            res=temp+pre+sums;
        }
        cout<<res<<endl;
    }
    return 0;
}