#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[100005];
vector<int>visited;
int n,m;
vector<vector<char>>ch;
void dfs1(int i,int j)
{
    dp[i*m+j]+=1;
    if(i<n-1 && ch[i+1][j]=='.' && !visited[i*m+j+m])
    {
        dfs1(i+1,j);
    }
    if(j<m-1 && ch[i][j+1]=='.' && !visited[i*m+j+1])
    {
        dfs1(i,j+1);
    }
}

void dfs2(int i,int j)
{
    dp[i*m+j]+=1;
    if(i>0 && ch[i-1][j]=='.' && !visited[i*m+j-m])
    {
        dfs2(i-1,j);
    }
    if(j>0 && ch[i][j-1]=='.' && !visited[i*m+j-1])
    {
        dfs2(i,j-1);
    }
}
void sol()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        vector<char>value(m);
        ch.push_back(value);
        for(int j=0;j<m;++j)
        {
            cin>>ch[i][j];
        }
    }
    visited.assign(n*m+1,0);
    dfs1(0,0);
    visited.assign(n*m+1,0);
    dfs2(n-1,m-1);
    if(dp[0]==1)
    {
        cout<<0;
        return;
    }
    int distance[n+m+1];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(dp[i*m+j]>1)
            {
                // distance[i+j]=dp[i*m+j];
                distance[i+j]+=1;
                // dp[i*m+j]=0;
            }
        }
    }
    int ans=INT_MAX;
    for(int i=1;i<=n+m-3;++i)
    {
        ans=min(ans,distance[i]);
    }
    if(ans<=2)
    {
        cout<<2;
        return;
    }
    else
    {
        cout<<2;
        return;
    }
}
signed main()
{
    sol();
    return 0;
}