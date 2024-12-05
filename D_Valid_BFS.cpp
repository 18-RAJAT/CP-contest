#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>sequence(n);
    for(int i=0;i<n;++i)
    {
        cin>>sequence[i];
    }
    if(sequence[0]!=1)
    {
        cout<<"No";
        return;
    }
    vector<int>pos(n+1);
    for(int i=0;i<n;++i)
    {
        pos[sequence[i]]=i;
    }
    vector<bool>visited(n+1,false);
    int idx=0;
    queue<int>q;
    q.push(sequence[0]);
    visited[sequence[0]]=true;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        vector<int>unvisited;
        for(int nbg:adj[curr])
        {
            if(!visited[nbg])
            {
                unvisited.push_back(nbg);
            }
        }
        sort(unvisited.begin(),unvisited.end(),[&](int a,int b){return pos[a]<pos[b];});
        idx++;
        for(int nbg:unvisited)
        {
            if(idx>=n || sequence[idx]!=nbg)
            {
                cout<<"No";
                return;
            }
            visited[nbg]=true;
            q.push(nbg);
            idx++;
        }
        idx--;
    }
    cout<<"Yes";
}
signed main()
{
    sol();
    return 0;
}