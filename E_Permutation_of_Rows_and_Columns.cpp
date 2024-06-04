#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid1(n,vector<int>(m,0)),grid2(n,vector<int>(m,0)),t1(m,vector<int>(n)),t2(m,vector<int>(n));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>grid1[i][j];
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>grid2[i][j];
        }
    }
    multiset<multiset<int>>r,c;
    for(auto& it:grid1)
    {
        r.insert(multiset<int>(it.begin(),it.end()));
    }
    for(auto& it:grid2)
    {
        c.insert(multiset<int>(it.begin(),it.end()));
    }
    if(r!=c)
    {
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            t1[j][i]=grid1[i][j],t2[j][i]=grid2[i][j];
        }
    }
    for(auto& it:t1)
    {
        r.insert(multiset<int>(it.begin(),it.end()));
    }
    for(auto& it:t2)
    {
        c.insert(multiset<int>(it.begin(),it.end()));
    }
    cout<<((r==c)?"YES":"NO")<<endl;
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