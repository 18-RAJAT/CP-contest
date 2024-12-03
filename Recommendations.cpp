#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> segments(n);
    
    // Read all segments
    for(int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }
    
    // For each user i
    for(int i = 0; i < n; i++) {
        vector<int> predictors;
        
        // Find all predictors for user i
        for(int j = 0; j < n; j++) {
            if(i != j && 
               segments[j].first <= segments[i].first && 
               segments[j].second >= segments[i].second) {
                predictors.push_back(j);
            }
        }
        
        // If no predictors, print 0
        if(predictors.empty()) {
            cout << 0 << " ";
            continue;
        }
        
        // Find the intersection of all predictor segments
        ll left = segments[predictors[0]].first;
        ll right = segments[predictors[0]].second;
        
        for(int j = 1; j < predictors.size(); j++) {
            left = max(left, segments[predictors[j]].first);
            right = min(right, segments[predictors[j]].second);
        }
        
        // Calculate strongly recommended tracks
        ll recommended = max(0LL, right - left + 1);
        
        // Subtract tracks that user i already likes
        if(segments[i].first <= right && segments[i].second >= left) {
            ll overlap_left = max(segments[i].first, left);
            ll overlap_right = min(segments[i].second, right);
            recommended -= (overlap_right - overlap_left + 1);
        }
        
        cout << recommended << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
