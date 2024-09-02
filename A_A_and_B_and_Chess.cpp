class Solution {
public:
    bool recur(const array<int,100001>& par,int u,int v)
    {
        for (;~u && u!=v;u=par[u]);
        return u==v?true:false;
    }
    void dfs(int node,int par,array<int,100001>& arr,map<int,vector<int>>& mp) {
        arr[node]=par;
        if (mp.find(node)!=mp.end())
        {
            for(auto& it:mp[node])
            {
                if(it!=par)dfs(it,node,arr,mp);
            }
        }
    }
    vector<vector<int>> twoMax(int n, int m, int rootServer, vector<vector<int>>& edges, vector<int>& requests) {
        array<int,100001>par;
        fill(par.begin(),par.end(),-1);
        map<int,vector<int>>mp;
        for(auto& it:edges)
        {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        dfs(rootServer,-1,par,mp);
        vector<vector<int>>res;
        for(auto& it:requests)
        {
            int maximum=0;
            array<int,2>ans={-1,-1};
            for(int i=n;i>=1 && maximum<2;--i)if(!recur(par,i,it))ans[maximum++]=i;
            res.push_back({ans[0],ans[1]});
        }
        return res;
    }
};
