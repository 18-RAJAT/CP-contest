#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int k,n,m;
    cin>>k>>n>>m;
    vector<string>grid(n);
    for(auto&it:grid)cin>>it;
    vector<vector<int>>dp(26,vector<int>((n+1)*(m+1),0));
    for(int c=0;c<26;++c)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                int tmp=i*(m+1)+j;
                dp[c][tmp]=dp[c][(i-1)*(m+1)+j]+dp[c][i*(m+1)+(j-1)]-dp[c][(i-1)*(m+1)+(j-1)];
                if(grid[i-1][j-1]-'a'==c)dp[c][tmp]++;
            }
        }
    }
    int res=k*(k+1)/2;
    vector<pair<int,int>>vp;
    for(int h=1;h*h<=res;++h)
    {
        if(res%h==0)
        {
            int w=res/h;
            if(h<=n && w<=m)vp.emplace_back(h,w);
            if(w!=h && w<=n && h<=m)vp.emplace_back(w,h);
        }
    }
    int mask=0;
    for(int l=1;l<=k;++l)mask|=(1LL<<l);
    for(auto it=vp.begin();it!=vp.end();++it)
    {
        int h=it->first,w=it->second;
        for(int i=1;i+h-1<=n;++i)
        {
            for(int j=1;j+w-1<=m;++j)
            {
                int f=0,get=0;
                bool ok=false;
                for(int c=0;c<26;++c)
                {
                    int i1=(i+h-1)*(m+1)+(j+w-1);
                    int i2=(i-1)*(m+1)+(j+w-1);
                    int i3=(i+h-1)*(m+1)+(j-1);
                    int i4=(i-1)*(m+1)+(j-1);
                    int ans=dp[c][i1]-dp[c][i2]-dp[c][i3]+dp[c][i4];
                    if(ans>0)
                    {
                        if(ans>k || (f&(1LL<<ans)))
                        {
                            ok=true;
                            break;
                        }
                        f|=(1LL<<ans);
                        get++;
                    }
                }
                if(!ok && get==k && f==mask)
                {
                    cout<<i<<" "<<j<<"\n"<<(i+h-1)<<" "<<(j+w-1);
                    return;
                }
            }
        }
    }
}
signed main()
{
    sol();
    return 0;
}