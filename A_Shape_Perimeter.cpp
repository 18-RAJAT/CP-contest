#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>vp(n);
    for(auto& it:vp)cin>>it.first>>it.second;
    int px=0,py=0;
    struct st
    {
        int x1,y1,x2,y2;
    };
    vector<st>r;
    for(int i=0;i<n;++i)
    {
        px+=vp[i].first;
        py+=vp[i].second;
        r.push_back(st{(int)px,(int)py,(int)(px+m),(int)(py+m)});
    }
    vector<int>X,Y;
    for(auto& it:r)
    {
        X.push_back(it.x1);
        X.push_back(it.x2);
        Y.push_back(it.y1);
        Y.push_back(it.y2);
    }
    sort(X.begin(),X.end());
    X.erase(unique(X.begin(),X.end()),X.end());
    sort(Y.begin(),Y.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    int s1=X.size(),s2=Y.size();
    vector<int>ar(s1-1),br(s2-1);
    for(int i=0;i<s1-1;++i)ar[i]=X[i+1]-X[i];
    for(int i=0;i<s2-1;++i)br[i]=Y[i+1]-Y[i];
    vector<vector<char>>g(s1-1,vector<char>(s2-1,0));
    for(auto& it:r)
    {
        int l1=lower_bound(X.begin(),X.end(),it.x1)-X.begin();
        int l2=lower_bound(X.begin(),X.end(),it.x2)-X.begin();
        int l3=lower_bound(Y.begin(),Y.end(),it.y1)-Y.begin();
        int l4=lower_bound(Y.begin(),Y.end(),it.y2)-Y.begin();
        for(int i=l1;i<l2;++i)
        {
            for(int j=l3;j<l4;++j)g[i][j]=1;
        }
    }
    int ans=0;
    for(int i=0;i<s1-1;++i)
    {
        for(int j=0;j<s2-1;++j)
        {
            if(g[i][j])
            {
                if(i==0 || g[i-1][j]==0)ans+=br[j];
                if(i==s1-2 || g[i+1][j]==0)ans+=br[j];
                if(j==0 || g[i][j-1]==0)ans+=ar[i];
                if(j==s2-2 || g[i][j+1]==0)ans+=ar[i];
            }
        }
    }
    cout<<ans<<endl;
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