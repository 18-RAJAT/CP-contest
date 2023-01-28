#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
const int MOD = 998244353;

int n, m;
int dp[1 << MAXN][MAXN];
vector<int> edges[MAXN];

int dfs(int removed, int mask) {
    if (dp[mask][removed] != -1) return dp[mask][removed];
    if (removed == 0) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                cnt++;
            }
        }
        return cnt > 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            for (int j = 0; j < edges[i].size(); j++) {
                int v = edges[i][j];
                if (!(mask & (1 << v))) {
                    ans=(ans+dfs(removed-1,mask|(1<<v)))%MOD;
                }}}}
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    memset(dp, -1, sizeof dp);
    // int ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = (ans + dfs(i, 0)) % MOD;
    }
    cout << ans << endl;
    return 0;
}
