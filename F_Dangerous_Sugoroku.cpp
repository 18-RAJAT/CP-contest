#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    vector<pair<int,int>>vp(m),pr;
    for(int i=0;i<m;++i)cin>>vp[i].first>>vp[i].second;
    int res=0;
    for(int i=0;i<m;++i)
    {
        int l=vp[i].first,r=vp[i].second;
        if(res+1<l)pr.push_back({res+1,l-1});
        res=r;
    }
    if(res<n)pr.push_back({res+1,n});
    if(m==0)pr.push_back({1,n});
    int k=pr.size(),tp=-1;
    for(int i=0;i<k;++i)
    {
        if(pr[i].first<=1 && 1<=pr[i].second)
        {
            tp=i;
            break;
        }
    }
    if(tp==-1)
    {
        cout<<"No";
        return;
    }
    vector<int>mn(k,LLONG_MAX),mx(k,LLONG_MIN);
    mn[tp]=1,mx[tp]=1;
    queue<int>q;
    q.push(tp);
    vector<int>ar(k,0);
    ar[tp]=1;
    /*
        Range->>
        [mn[i],mx[i]] bel=>>[l,r]
        [x+a,min(x+b,n)] ->>> [mn[i]+a,mx[i]+b] overlap maybe
        a<=jp<=b 
        bound:::
        mn[B]=min(mn[B],s)->>same as mx
    */
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        ar[cur]=0;
        int m1=mn[cur],m2=mx[cur],n1=m1+a,n2=min(m2+b,n);
        if(n<n1)continue;
        int LB=lower_bound(pr.begin(),pr.end(),make_pair(n1,0LL),[&](const pair<int,int>& p,const pair<int,int>& x)
                        {
                          return p.second<x.first;
                        })-pr.begin();

        while(LB<k && pr[LB].first<=n2)
        {
            int s=max(pr[LB].first,n1),e=min(pr[LB].second,n2);
            if(e<s)
            {
                LB++;
                continue;
            }
            int upd=0;
            if(mn[LB]>s)mn[LB]=s,upd=1;
            if(mx[LB]<e)mx[LB]=e,upd=1;
            if(upd && !ar[LB])
            {
                q.push(LB);
                ar[LB]=1;
            }
            LB++;
        }
    }
    int ans=0;
    for(int i=0;i<k;++i)
    {
        if(pr[i].first<=n && n<=pr[i].second)
        {
            if(mn[i]<=n && mx[i]>=n)
            {
                ans=1;
                break;
            }
        }
    }
    cout<<(ans?"Yes":"No");
}
signed main()
{
    sol(); 
    return 0;
}