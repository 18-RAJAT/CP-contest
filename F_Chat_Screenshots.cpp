#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+15;
int visited[N],traverse[N];
vector<int>adj[N];
void sol()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        adj[i].clear();
        visited[i]=0,traverse[i]=0;
    }
    function<bool(int)>dfs=[&](int node)->bool
    {
        visited[node]=1;
        traverse[node]=1;
        for(auto&it:adj[node])
        {
            if(visited[it]==0)
            {
                if(dfs(it))
                {
                    return true;
                }
            }
            else if(traverse[it])
            {
                return true;
            }
        }
        traverse[node]=0;//init again
        return false;
    };
    for(int i=0;i<k;++i)
    {
        vector<int>array(n);
        for(int j=0;j<n;++j)
        {
            cin>>array[j];
        }
        //adjacency list
        for(int j=2;j<n;++j)//from 2 to n check if there is a cycle
        {
            adj[array[j-1]].push_back(array[j]);
        }
    }
    auto print=[&]()->void
    {
        for(int i=1;i<=n;++i)
        {
            cout<<i<<": ";
            for(auto&it:adj[i])
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
    };
    // for(auto& it:adj)
    // {
    //     sort(it.begin(),it.end());
    //     it.erase(unique(it.begin(),it.end()),it.end());
    // }
    bool cycle=false;
    for(int i=1;i<=n;++i)
    {
        if(visited[i]==0)
        {
            if(dfs(i))
            {
                cycle=true;
                break;
            }
        }
    }
    // print();
    cout<<(!cycle?"YES":"NO")<<endl;
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