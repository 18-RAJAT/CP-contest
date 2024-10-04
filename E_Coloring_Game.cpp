// Problem: E. Coloring Game
// Contest: Codeforces - Pinely Round 4 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1991/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Author: Rajat.18
// Created: Fri 4/10/2024 10:53:16 GMT+5:30,India

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MaxNodes=1e4+10;
int n,m,color[MaxNodes];
vector<int>Adj[MaxNodes];
bool IsBipartite()
{
    queue<int>q;
    bool ok=true;
    for(int i=1;i<=n;++i)
    {
        if(color[i])continue;
        color[i]=1;
        q.push(i);
        while(!q.empty())
        {
            int currentNode=q.front();
            q.pop();
            for(int neighbor:Adj[currentNode])
            {
                if(!color[neighbor])
                {
                    color[neighbor]=3-color[currentNode];
                    q.push(neighbor);
                }
                else
                {
                    if(color[neighbor]==color[currentNode])
                    {
                        ok=false;
                    }
                }
            }
        }
    }
    return ok;
}
void solve()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int u,v;
        cin>>u>>v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    bool isTwoColored=IsBipartite();
    vector<int>AliceGroup,BobGroup;
    for(int i=1;i<=n;++i)
    {
        if(color[i]==1)
        {
            AliceGroup.push_back(i);
        }
        else
        {
            BobGroup.push_back(i);
        }
    }
    if(isTwoColored)
    {
        cout<<"Bob"<<endl;
        for(int i=1;i<=n;++i)
        {
            int x,y;
            cin>>x>>y;
            if(y<x)
            {
                swap(x,y);
            }
            if(x==1 && !AliceGroup.empty())
            {
                cout<<AliceGroup.back()<<" 1"<<endl;
                AliceGroup.pop_back();
            }
            else
            {
                cout<<BobGroup.back()<<" "<<y<<endl;
                BobGroup.pop_back();
            }
        }
    }
    else
    {
        cout<<"Alice"<<endl;
        int x,y;
        for(int i=0;i<n;++i)
        {
            cout<<"1 2"<<endl;
            cin>>x>>y;
        }
    }
    for(int i=0;i<=n;++i)
    {
        Adj[i].clear();
        color[i]=0;
    }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}