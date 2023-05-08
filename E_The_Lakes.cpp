#include<bits/stdc++.h>

void sol()
{
    static std::vector<std::pair<int,int>>directions={{1,0},{0,1},{-1,0},{0,-1}};

    int n,m;
    std::cin>>n>>m;

    std::vector<std::vector<int>>adj(n,std::vector<int>(m));
    for(int i=0;i<=n-1;++i)
    {
        for(int j=0;j<=m-1;++j)
        {
            std::cin>>adj[i][j];
        }
    }
    auto validSeq=[&](int x,int y)->int
    {
        return (x>=0 and x<=n-1 and y>=0 and y<=m-1);
    };
    int ans=0,curr=0;
    std::vector<std::vector<int>>vis(n,std::vector<int>(m));

    auto dfs=[&](int x,int y,auto&& dfs)->void
    {
        // if(vis[x][y])
        // {
        //     return;
        // }
        vis[x][y]=1;
        curr+=adj[x][y];
        for(auto&[dx,dy]:directions)
        {
            int nx=x+dx,ny=y+dy;
            if(validSeq(nx,ny) and (not vis[nx][ny]) and adj[nx][ny]!=0)
            {
                // vis[nx][ny]=1;
                dfs(nx,ny,dfs);
            }
        }
    };
    for(int i=0;i<=n-1;++i)
    {
        for(int j=0;j<=m-1;++j)
        {
            if(not vis[i][j] and adj[i][j]!=0)
            {
                dfs(i,j,dfs);
                ans=std::max(ans,curr);
                curr=0;
            }
        }
    }
    std::cout<<ans<<"\n";
}

int main()
{
    int tc;
    std::cin>>tc;
    while(tc--)
    {
        sol();
    }
    return 0;
}