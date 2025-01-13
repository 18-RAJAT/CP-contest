#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<vector<int>>ar(n,vector<int>(m,0));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)cin>>ar[i][j];
    }
    vector<pair<int,int>>vp;
    int x=0,y=0;
    vp.push_back({x,y});
    for(auto& it:s)
    {
        (it=='D')?x++:y++;
        vp.push_back({x,y});
    }
    vector<vector<int>>chk(n,vector<int>(m,0));
    for(auto& it:vp)chk[it.first][it.second]=1;
    vector<int>R(n,0),C(m,0);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(!chk[i][j])R[i]+=ar[i][j],C[j]+=ar[i][j];
        }
    }
    vector<pair<int,int>>rw(n,{-1,-1}),cl(m,{-1,-1});
    for(auto& it:vp)rw[it.first]=it,cl[it.second]=it;
    vector<int>c(n,0),d(m,0);
    for(int i=0;i<n;++i)c[i]=-R[i];
    for(int j=0;j<m;++j)d[j]=-C[j];
    vector<int>Row(n,0),Cols(m,0);
    vector<vector<int>> b(n,vector<int>(m,0));
    for(auto& it:vp)
    {
        //same
        int i=it.first,j=it.second,ok1=(rw[i]==it),ok2=(cl[j]==it);
        if(ok1 && ok2)b[i][j]=c[i]-Row[i],b[i][j]=d[j]-Cols[j];
        else if(ok1)b[i][j]=c[i]-Row[i];
        else if(ok2)b[i][j]=d[j]-Cols[j];
        else b[i][j]=0;
        Row[i]+=b[i][j],Cols[j]+=b[i][j];
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cout<<(chk[i][j]?b[i][j]:ar[i][j])<<" ";
        }
        cout<<endl;
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