#include<bits/stdc++.h>
using namespace std;
#define int long long
int length=0,cnt=0;
vector<int>tree[10'00'05];

void dfs(int node,int parent,int depth)
{
    if(tree[node].size()==1 && tree[node][0]==parent)//if it is a leaf node then add the depth to the length and increase the count by 1
    {
        length+=depth;//length of the path
        cnt++;
        return;
    }
    else
    {
        cnt=0;
    }
    for(auto& child:tree[node])
    {
        if(child==parent)
        {
            continue;
        }
        dfs(child,node,depth+1);
    }
    assert(~parent);
}
void sol()
{
    int n;
    cin>>n;
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
    dfs(1,0,0);
    double ans=0;
    ans=(double)length/cnt;
    cout<<fixed<<setprecision(15)<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}