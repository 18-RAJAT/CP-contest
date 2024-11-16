#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<vector<int>>adj(n);
    for(int i=1;i<n;++i)
    {
        int p;
        cin>>p;
        adj[p-1].push_back(i);
    }
    vector<int>tree(n);
    for(int i=n-1;~i;--i)
    {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int v:adj[i])
        {
            pq.push(tree[v]);
        }
        if(pq.empty())tree[i]=0;
        else if(pq.size()==1)tree[i]=1+pq.top();
        else
        {
            while(pq.size()>=2)
            {
                int x=pq.top();
                pq.pop();
                int y=pq.top();
                pq.pop();
                pq.push(y+1);
            }
            tree[i]=pq.top();
        }
    }
    cout<<tree[0]<<endl;
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