#include<bits/stdc++.h>
using namespace std;
#define int long long

void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>>vp(n);
    for(int i=0;i<n;++i)cin>>vp[i].first>>vp[i].second;
    if(n==1)
    {
        cout<<0<<endl;
        return;
    }
    vector<int>Mini(n,1e18);
    vector<bool>vis(n,false);
    Mini[0]=0;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        int cur=1e18,u=-1;
        for(int j=0;j<n;++j)
        {
            if(!vis[j] && Mini[j]<cur)
            {
                cur=Mini[j];
                u=j;
            }
        }
        if(u==-1)break;
        vis[u]=true;
        ans=max(ans,cur);
        for(int v=0;v<n;++v)
        {
            if(!vis[v])
            {
                int t,x1=vp[u].first,y1=vp[u].second,x2=vp[v].first,y2=vp[v].second;
                if(x1==x2 || y1==y2)
                {
                    if(x1==x2)
                    {
                        int diff=abs(y1-y2);
                        t=(diff+1)/2;
                    }
                    else
                    {
                        int diff=abs(x1-x2);
                        t=(diff+1)/2;
                    }
                }
                else
                {
                    int X=abs(x1-x2),Y=abs(y1-y2);
                    t=max(X,Y);
                }
                if(t<Mini[v])Mini[v]=t;
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