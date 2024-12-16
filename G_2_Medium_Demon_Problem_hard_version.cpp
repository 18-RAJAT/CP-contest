#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;++i)cin>>arr[i];
    vector<vector<int>>adj(n,vector<int>());
    for(int i=0;i<n;++i)
    {
        int init=arr[i]-1;
        adj[init].push_back(i);
    }
    vector<int>pref(n,1),suf(n,0);
    for(int i=0;i<n;++i)suf[i]=adj[i].size();
    int y=1,NN=n+10;
    bool ok=false;
    vector<int>curr(n,0);
    while(y<=NN)
    {
        for(int i=0;i<n;++i)
        {
            int chk=(suf[i]>=1)?1:0;
            int cnt=0;
            for(auto& it:adj[i])
            {
                if(suf[it]>=1)cnt++;
            }
            curr[i]=suf[i]-chk+cnt;
        }
        y++;
        if(y>=2)
        {
            bool F=true;
            for(int i=0;i<n;++i)
            {
                if(curr[i]!=pref[i])
                {
                    F=false;
                    break;
                }
            }
            if(F)
            {
                cout<<y<<endl;
                ok=true;
                break;
            }
        }
        pref=suf,suf=curr;
    }
    if(!ok)cout<<y<<endl;
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