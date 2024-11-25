#include <bits/stdc++.h>
using namespace std;
#define int long long
class UnionFind
{
public:
    vector<int>parent,size;
    UnionFind(int n):parent(n),size(n,1)
    {
        for(int i=0;i<n;++i)parent[i]=i;
    }
    int find(int x)
    {
        if(parent[x]!=x)parent[x]=find(parent[x]);
        return parent[x];
    }
    void unite(int x,int y)
    {
        int rootX=find(x),rootY=find(y);
        if(rootX!=rootY)
        {
            parent[rootX]=rootY;
            size[rootY]+=size[rootX];
        }
    }
    int get(int x)
    {
        return size[find(x)];
    }
};
void sol()
{
    int n,m;
    cin>>n>>m;
    UnionFind uf(n);
    for(int i=0;i<m;++i)
    {
        int k;
        cin>>k;
        if(k>1)
        {
            int x;
            cin>>x;
            x--;
            for(int j=1;j<k;++j)
            {
                int y;
                cin>>y;
                y--;
                uf.unite(x,y);
            }
        }
        else if(k==1)
        {
            int x;
            cin>>x;
            x--;
        }
    }
    for(int i=0;i<n;++i)cout<<uf.get(i)<<" ";
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}