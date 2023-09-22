#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<bool> onStack;

bool hasCycle(int v, int parent) {
    visited[v] = true;
    onStack[v] = true;

    for (int u : adj[v]) {
        if (!visited[u]) {
            if (hasCycle(u, v))
                return true;
        } else if (onStack[u] && u != parent) {
            return true;
        }
    }

    onStack[v] = false;
    return false;
}

bool canEscape(int n, int a, int b) {
    visited.assign(n + 1, false);
    onStack.assign(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (hasCycle(i, -1))
                return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        adj.assign(n + 1, vector<int>());
        
        for (int i = 1; i <= n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (canEscape(n, a, b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
