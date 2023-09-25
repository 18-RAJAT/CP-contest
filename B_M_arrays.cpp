#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
vector<int>adj[N];
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),visited(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        a[i]%=m;
        adj[a[i]].push_back(i);
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(visited[i])
        {
            continue;
        }
        ans++;
        int curr=i;
        while(1)
        {
            // adj[a[curr]].erase(curr);
            visited[curr]=1;
            if(adj[(m-a[curr])%m].size()==0)
            {
                break;
            }
            curr=adj[(m-a[curr])%m].back();
            // curr%=m;
            // cout<<"current state-> "<<curr<<"\n";
            adj[(m-a[curr])%m].pop_back();
        }
    }
    cout<<ans<<"\n";
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