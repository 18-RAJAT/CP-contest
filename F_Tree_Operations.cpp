#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2005;
vector<int> adj[MAXN];
vector<int> subtree[MAXN];
ll a[MAXN];
int n, x;

// Function to build subtree lists using DFS
void buildSubtree(int v, int parent) {
    subtree[v].push_back(v);
    for(int u : adj[v]) {
        if(u != parent) {
            buildSubtree(u, v);
            // Add all nodes from child's subtree
            subtree[v].insert(subtree[v].end(), subtree[u].begin(), subtree[u].end());
        }
    }
}

// Function to solve each test case
ll solve() {
    cin >> n >> x;
    
    // Read initial values
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // Clear and build adjacency list
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        subtree[i].clear();
    }
    
    // Read edges
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Build subtrees
    buildSubtree(x, 0);
    
    // For each node, check if we can reach all non-zero values in its cycles
    ll operations = 0;
    vector<ll> values(n + 1);
    for(int i = 1; i <= n; i++) {
        values[i] = a[i];
    }
    
    // Try up to 2*max_value operations
    ll max_value = 0;
    for(int i = 1; i <= n; i++) {
        max_value = max(max_value, abs(values[i]));
    }
    
    ll max_ops = 2 * n * max_value;
    while(operations <= max_ops) {
        bool all_zero = true;
        for(int i = 1; i <= n; i++) {
            if(values[i] != 0) {
                all_zero = false;
                break;
            }
        }
        
        if(all_zero) return operations;
        
        // Get current node for this operation
        int curr_node = ((operations % n) + 1);
        
        // Find non-zero value in subtree that we can modify
        bool found = false;
        for(int node : subtree[curr_node]) {
            if(values[node] > 0) {
                values[node]--;
                found = true;
                break;
            } else if(values[node] < 0) {
                values[node]++;
                found = true;
                break;
            }
        }
        
        if(!found) {
            // If we can't make progress in this cycle of n operations,
            // it's impossible
            if(operations % n == n-1) return -1;
        }
        
        operations++;
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        cout << solve() << "\n";
    }
    
    return 0;
}