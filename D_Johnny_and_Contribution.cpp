#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
void undirected(int a,int b,vector<int>adj[])
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}
void sol()
{
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        undirected(a,b,adj);
    }
    vector<vector<int>>blogs(n+1);
    vector<int>valid(n+1);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        blogs[x].push_back(i);
        valid[i]=x;
    }
    vector<int>col(n+1,INT_MAX);
    bool check=true;
    vector<int>ans;
    for(int i=1;i<=n;i++)
    {
        for(auto& it:blogs[i])
        {
            set<int>st;
            for(auto& nbg:adj[it])
            {
                if(col[nbg]==i)
                {
                    check=false;
                    break;
                }
                if(col[nbg]!=INT_MAX)
                {
                    st.insert(col[nbg]);
                }
            }
            ans.push_back(it);
            col[it]=i;
            if(st.size()!=i-1)
            {
                check=false;
                break;
            }
            if(!check)
            {
                break;
            }
        }
    }
    if(!check)
    {
        cout<<-1<<endl;
    }
    else
    {
        for(auto& it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}