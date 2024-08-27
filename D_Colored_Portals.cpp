#include<bits/stdc++.h>
using namespace std;
#define int long long
int path(string s)
{
    unordered_map<string,int>mp=
    {
        {"BG",0},{"BR",1},{"BY",2},
        {"GR",3},{"GY",4},{"RY",5}
    };
    return mp[s];
}
vector<int>adj_ele(int x)
{
    if(x==0)return{0,1,2,3,4};
    if(x==1)return{0,1,2,3,5};
    if(x==2)return{0,1,2,4,5};
    if(x==3)return{0,3,4,1,5};
    if(x==4)return{0,2,3,4,5};
    if(x==5)return{1,2,3,4,5};
}
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<vector<int>>adj(6);
    vector<string>s(n+6);
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        adj[path(s[i])].push_back(i);
    }
    function<int(int,int)>query=[&](int l,int r)->int
    {
        if(r<l)swap(l,r);
        int ans=1e9;
        for(int k1=0;k1<6;++k1)
        {
            if(path(s[l])!=k1){continue;}
            for(auto& it:adj_ele(k1))
            {
                auto UB=upper_bound(adj[it].begin(),adj[it].end(),l);
                for(auto& i:{0,1,2})
                {
                    if(UB!=adj[it].end())
                    {
                        if(path(s[*UB])!=it){continue;}
                        for(auto it1:adj_ele(path(s[*UB])))
                        {
                            if(path(s[r])==it1)
                            {
                                ans=min(ans,abs(l-*UB)+abs(*UB-r));
                            }
                        }
                    }
                    if(UB==adj[it].begin())
                    {
                        break;
                    }
                    UB--;
                }
            }
        }
        return (ans==1e9?-1:ans);
    };
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
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