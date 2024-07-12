#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>adj[200005],ans;
void iterative_dfs(int start)
{
    stack<pair<int,int>>stk;
    stk.push(make_pair(start,-1));
    while(!stk.empty())
    {
        pair<int,int>tp=stk.top();
        int f=tp.first,s=tp.second;
        stk.pop();
        for(auto& it:adj[f])
        {
            if(it!=s)
            {
                if(adj[it].empty())ans.push_back(it);
            }
        }
        for(auto& it:adj[s])
        {
            if(it!=s)
            {
                ans.push_back(it+1);
            }
            else
            {
                ans.push_back(0),ans.pop_back();
            }
        }
    }
}

// while (!stk.empty()) {
//         pair<int, int> current = stk.top();
//         int c = current.first;
//         int p = current.second;
//         stk.pop();
        
//         for (auto &it : adj[c]) {
//             if (it != p) {
//                 if (adj[it].empty()) ans.push_back(it);
//             }
//         }
        
//         for (auto &it : adj[c]) {
//             if (it != p) {
//                 if (!adj[it].empty()) ans.push_back(it);
//                 stk.push({it, c});
//             }
//         }
//     }
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto& it:a)cin>>it;
    for(int i=0;i<=n;++i)
    {
        adj[i].clear();
    }   
    for(int i=0;i<n;++i)
    {
        adj[a[i]].push_back(i+1);
    }
    ans.clear();
    (adj[0].empty())?iterative_dfs(n+1):iterative_dfs(0);

    vector<int>temp;
    for(auto& it:ans)
    {
        if(it>0 && it<=n)temp.push_back(it);
    }
    int per=0;
    for(int i=0;i<n;++i)
    {
        if(i+1<a[i])per=max(per,i+1);
    }
    cout<<per<<endl;
    for(auto& it:temp)cout<<it<<" ";
    cout<<endl;
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