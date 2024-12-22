#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<int>arr(q);
    for(int& x:arr)cin>>x;
    vector<pair<int,int>>vp;
    vp.emplace_back(m,m);
    vector<int>ans;
    for(auto& it:arr)
    {
        vector<pair<int,int>>Nvp;
        for(auto& it1:vp)
        {
            int l=it1.first,r=it1.second;
            if(l<=it && it<=r)
            {
                Nvp.emplace_back(1,1);
                //[Range -> 1,1] [Range -> n,n]
                if(l<=it-1)
                {
                    int nl=l+1,nr=it;
                    if(nl<=nr) Nvp.emplace_back(nl,nr);
                }
                if(it+1<=r)
                {
                    int nl=it+1,nr=r;
                    if(nl<=nr) Nvp.emplace_back(nl,nr);
                }
            }
            else if(r<it)
            {
                int nl=l+1,nr=r+1;
                if(nl>n) continue;
                nr=min(nr,n);
                if(nl<=nr) Nvp.emplace_back(nl,nr);
            }
            else if(l>it) Nvp.emplace_back(l,r);
            //move the range to ->L
            if(l<=it && it<=r)
            {
                Nvp.emplace_back(n,n);
                if(l<=it-1)
                {
                    int nl=l,nr=it-1;
                    if(nl<=nr) Nvp.emplace_back(nl,nr);
                }
                if(it+1<=r)
                {
                    int nl=it,nr=r-1;
                    if(nl<=nr) Nvp.emplace_back(nl,nr);
                }
            }
            else if(r<it) Nvp.emplace_back(l,r);
            else if(l>it)
            {
                int nl=l-1,nr=r-1;
                if(nl<1) nl=1;
                if(nl<=nr) Nvp.emplace_back(nl,nr);
            }
        }
        /*
            let 5:
            (6 5 3, 1 2 3, 2 1 4)
        */
        if(Nvp.empty()) vp.clear();
        else
        {
            sort(Nvp.begin(),Nvp.end());
            vector<pair<int,int>>res;
            res.emplace_back(Nvp[0].first,Nvp[0].second);
            for(int i=1;i<Nvp.size();++i)
            {
                if(Nvp[i].first<=res.back().second+1) res.back().second=max(res.back().second,Nvp[i].second);
                else res.emplace_back(Nvp[i].first,Nvp[i].second);
            }
            vp=res;
        }
        int tot=0;
        for(auto& it:vp) tot+=(it.second-it.first+1);
        ans.emplace_back(tot);
    }
    for(int i=0;i<ans.size();++i)
    {
        if(i>=1)cout<<" ";
        cout<<ans[i];
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