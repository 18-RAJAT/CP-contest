#include<bits/stdc++.h>
using namespace std;
#define int long long

void sol() {
    int n;
    cin >> n;
    
    // Create adjacency list for the tree
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    // Read the sequence to check
    vector<int> sequence(n);
    for(int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    
    // First element must be 1
    if(sequence[0] != 1) {
        cout << "No\n";
        return;
    }
    
    // For each vertex, store its position in the sequence
    vector<int> pos(n + 1);
    for(int i = 0; i < n; i++) {
        pos[sequence[i]] = i;
    }
    
    // For each vertex in sequence, check if its unvisited neighbors
    // appear contiguously after it in valid BFS order
    vector<bool> visited(n + 1, false);
    int idx = 0;
    queue<int> q;
    q.push(sequence[0]);
    visited[sequence[0]] = true;
    
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        
        // Get all unvisited neighbors
        vector<int> unvisited;
        for(int neighbor : adj[curr]) {
            if(!visited[neighbor]) {
                unvisited.push_back(neighbor);
            }
        }
        
        // Sort neighbors by their position in sequence
        sort(unvisited.begin(), unvisited.end(), 
             [&](int a, int b) { return pos[a] < pos[b]; });
        
        // Check if these neighbors appear next in sequence
        idx++;
        for(int neighbor : unvisited) {
            if(idx >= n || sequence[idx] != neighbor) {
                cout << "No\n";
                return;
            }
            visited[neighbor] = true;
            q.push(neighbor);
            idx++;
        }
        idx--;
    }
    
    cout << "Yes\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    sol();
    
    return 0;
}
