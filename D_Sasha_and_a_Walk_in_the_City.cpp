#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

vector<vector<int>> adj;
vector<int> dp_in, dp_out;

void dfs(int u, int parent) {
    dp_in[u] = 1;
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            dp_in[u] = (1LL * dp_in[u] * (dp_out[v] + dp_in[v])) % MOD;
        }
    }
    dp_out[u] = 1;
    for (int v : adj[u]) {
        if (v != parent) {
            dp_out[u] = (1LL * dp_out[u] * (dp_out[v] + dp_in[v])) % MOD;
        }
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        adj.assign(n + 1, vector<int>());
        dp_in.assign(n + 1, 0);
        dp_out.assign(n + 1, 0);
        
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(1, 0);
        
        int ans = (dp_in[1] + dp_out[1]) % MOD;
        cout << ans << endl;
    }
    
    return 0;
}
