#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>ch;
    ch.assign(n+5,vector<char>(m+5));
    vector<pair<int,int>>vp;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>ch[i][j];
            if(ch[i][j]=='#')vp.push_back({i,j});
        }
    }
    sort(vp.begin(),vp.end());
    cout<<(vp.front().first+vp.back().first)/2<<" "<<(vp.front().second+vp.back().second)/2<<endl;
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