#include<bits/stdc++.h>

void F()
{
    int n,m;
    std::cin>>n>>m;

    std::vector<std::vector<int>>adj(n+1);
    for(int i=0;i<=m-1;++i)
    {
        int u,v;
        std::cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::unordered_set<int>nbg;
    for(int i=0;i<=n;++i)
    {
        // nbg.insert(i);
        if(adj[i].size()==1)
        {
            // nbg.insert(i);
            nbg.insert(adj[i].front());
        }
    }
    int y=0;
    for(auto& it:adj[*nbg.begin()])
    {
        // cout<<it<<" ";
        y+=(adj[it].size()==1);
    }
    std::cout<<nbg.size()<<" "<<y<<"\n";
}

int main()
{
    int tc;
    std::cin>>tc;
    while(tc--)
    {
        F();
    }
    return 0;
}