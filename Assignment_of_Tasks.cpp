#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),s(n),f(m);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>s[i];
    for(int i=0;i<m;++i)cin>>f[i];
    int l=0,r=2e15;
    auto recur=[&](int t)
    {
        int res=0;
        for(int j=0;j<m && res<n;++j)
        {
            int avail=0;
            while(res<n)
            {
                int L=max(avail,s[res]),R=L+f[j]*a[res];
                if(R>t)
                {
                    break;
                }
                avail=R;
                res++;
            }
        }
        return res>=n;
    };
    while(l<r)
    {
        int mid=l+(r-l)/2;
        (recur(mid))?r=mid:l=mid+1;
    }
    cout<<l<<endl;
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