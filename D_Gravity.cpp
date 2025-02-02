#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,w;
    cin>>n>>w;
    vector<vector<pair<int,int>>>col(w+1);
    vector<int>bx(n+1,0),by(n+1,0);
    for(int i=1;i<=n;++i)
    {
        int x,y;
        cin>>x>>y;
        col[x].push_back({y,i});
        bx[i]=x;
    }
    for(int x=1;x<=w;++x)
    {
        sort(col[x].begin(),col[x].end());
        for(int j=0;j<(int)col[x].size();++j)by[col[x][j].second]=j+1;
    }
    int res=INT_MAX;
    for(int x=1;x<=w;++x)res=min(res,(int)col[x].size());
    if(res==0)
    {
        int q;
        cin>>q;
        while(q--)
        {
            int t,a;
            cin>>t>>a;
            cout<<"Yes"<<endl;
        }
        return;
    }
    vector<int>ar(res+1,0);
    for(int x=1;x<=w;++x)
    {
        int m=col[x].size();
        vector<int>tp(m+1,0);
        tp[1]=col[x][0].first;
        for(int j=2;j<=m;++j)tp[j]=max(col[x][j-1].first,tp[j-1]+1);
        for(int r=1;r<=min(m,res);++r)ar[r]=max(ar[r],tp[r]);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int t,a;
        cin>>t>>a;
        int chk=by[a],L=1,R=res,rem=0;
        while(L<=R)
        {
            int mid=(L+R)/2;
            (ar[mid]<=t?rem=mid,L=mid+1:R=mid-1);
        }
        cout<<(rem<chk?"Yes":"No")<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}