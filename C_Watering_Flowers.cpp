#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x1,y1,x2,y2;
    cin>>n>>x1>>y1>>x2>>y2;
    vector<pair<int,int>>vp;
    for(int i=0;i<n;++i)
    {
        int x,y;cin>>x>>y;
        vp.push_back({(x-x1)*(x-x1)+(y-y1)*(y-y1),(x-x2)*(x-x2)+(y-y2)*(y-y2)});
    }
    int Ans=1e18;
    vp.push_back({0,0});
    for(auto& it:vp)
    {
        int F=it.first,S=0;
        for(auto& it1:vp)if(F<it1.first)S=max(S,it1.second);
        Ans=min(Ans,F+S);
    }
    cout<<Ans<<endl;
}
signed main()
{
    sol();
    return 0;
}