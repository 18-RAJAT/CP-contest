#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>r(n+1);
    for(int i=1;i<=n;++i)cin>>r[i];
    vector<vector<int>>arr(n+1);
    //Rajat joshi template(Bfs=Monotonic queue)
    vector<int>In(n+1,0);
    for(int i=1;i<=n;++i)
    {
        arr[r[i]].push_back(i);
        In[r[i]]++;
    }
    queue<int>q;
    for(int i=1;i<=n;++i)if(In[i]==0)q.push(i);
    vector<bool>cycle(n+1,false);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        int v=r[u];
        In[v]--;
        if(In[v]==0)
        {
            q.push(v);
        }
    }
    vector<int>detect(n+1,-1);
    queue<int>Bfs;
    for(int i=1;i<=n;++i)
    {
        if(In[i]>=1)
        {
            detect[i]=0;
            Bfs.push(i);
        }
    }
    while(!Bfs.empty())
    {
        int u=Bfs.front();Bfs.pop();
        for(auto& v:arr[u])
        {
            if(detect[v]==-1)
            {
                detect[v]=detect[u]+1;
                Bfs.push(v);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i)ans=max(ans,detect[i]);
    cout<<(ans+2)<<endl;
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