#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int>tree[10'00'05];
vector<int>cats;
int n,m,ans;

void dfs(int node,int parent,int current_child,int maximum_vertices)
{
    cats[node-1]==1?current_child++:current_child=0;//if cat is present then increase current_child else make it 0
    maximum_vertices=max<int>(maximum_vertices,current_child);
    // cout<<maximum_vertices<<endl;//debug
    int count=0;
    for(auto& child:tree[node])
    {
        if(child!=parent)
        {
            dfs(child,node,current_child,maximum_vertices);
            count++;
        }
    }
    if(count==0 && maximum_vertices<=m)
    {
        ans++;
    }
}

void sol()
{
    cin>>n>>m;
    ans=0;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        cats.push_back(x);
    }
    auto add_edge=[&](int src,int dest)->void
    {
        tree[src].push_back(dest);
        tree[dest].push_back(src);
    };
    for(int i=1;i<n;++i)
    {
        int source,destination;
        cin>>source>>destination;
        add_edge(source,destination);
    }
    dfs(1,-1,0,0);//root node is 1 and parent is -1 and current_child is 0 and maximum_vertices is 0
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}