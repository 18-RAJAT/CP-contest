#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Dsu
{
    vector<int>parent;
    Dsu(int n)
    {
        parent.resize(n);
        iota(parent.begin(),parent.end(),0LL);
    }
    int find(int x)
    {
        return x==parent[x]?x:parent[x]=find(parent[x]);
    }
    void merge(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x!=y)
        parent[x]=y;
    }
};
void sol()
{
    int n,m;
    cin>>n>>m;
    Dsu D(n);
    for(int i=0;i<m;++i)
    {
        int u,v;
        cin>>u>>v;
        D.merge(u-1,v-1);
    }
    int k;
    cin>>k;
    set<pair<int,int>>st;
    for(int i=0;i<k;++i)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        st.insert({D.find(x),D.find(y)});
        st.insert({D.find(y),D.find(x)});
    }
    int q;
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        cout<<(st.count({D.find(a),D.find(b)})?"No":"Yes")<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}