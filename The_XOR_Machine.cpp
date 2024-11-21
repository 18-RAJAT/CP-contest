#include<bits/stdc++.h>
using namespace std;
#define int long long
int count(int x,int l,int r,int m)
{
    int y1=x^l,y2=x^r;
    int L=min(y1,y2),R=max(y1,y2);
    int mx=0;
    for(int i=0;i<m;++i)
    {
        int num=L-i>=0?(L-i):0;
        int mini=(num+m-1)/m;
        if(R<i)continue;
        int maxi=(R-i)/m;
        if(maxi<mini)continue;
        int count=maxi-mini+1;
        if(count>mx)mx=count;
    }
    return mx;
}
void sol()
{
    int x,l,r,m;
    cin>>x>>l>>r>>m;
    int n=r-l+1,maxi=0;
    if(m<=1e6)
    {
        if(n<=1e6)
        {
            vector<int>freq(m,0);
            for(int i=l;i<=r;++i)
            {
                int y=x^i;
                int res=y%m;
                freq[res]++;
                if(freq[res]>maxi)maxi=freq[res];
            }
        }
        else maxi=count(x,l,r,m);
    }
    else
    {
        if(n<=1e6)
        {
            unordered_map<int,int>mp;
            for(int i=l;i<=r;++i)
            {
                int y=x^i;
                int res=y%m;
                mp[res]++;
                if(mp[res]>maxi)maxi=mp[res];
            }
        }
        else
        {
            int res=(n+m-1)/m;
            maxi=res+2;
        }
    }
    cout<<maxi<<endl;
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