#include <bits/stdc++.h>
using namespace std;
#define ll long long

// First approach: Direct translation from Python using sliding window
ll findGoodSubarrays1(vector<int>& a, int k, vector<pair<int,int>>& queries) {
    int n = a.size();
    unordered_map<int, int> freq;
    int left = 0, right = 0;
    ll result = 0;
    const int mod = 1e9 + 7;
    
    for(auto query : queries) {
        int l = query.first, r = query.second;
        
        // Move right pointer
        while(right < r) {
            freq[a[right]]++;
            right++;
        }
        
        // Move left pointer
        while(left < l - 1) {
            freq[a[left]]--;
            if(freq[a[left]] == 0) {
                freq.erase(a[left]);
            }
            left++;
        }
        
        // Check if subarray is good
        bool isGood = true;
        for(auto p : freq) {
            if(p.second != k) {
                isGood = false;
                break;
            }
        }
        
        if(isGood) {
            result = (result + l) % mod;
        }
    }
    
    return result;
}

// Second approach: Using prefix sum arrays for optimization
ll findGoodSubarrays2(vector<int>& a, int k, vector<pair<int,int>>& queries) {
    int n = a.size();
    ll result = 0;
    const int mod = 1e9 + 7;
    
    // Create prefix sum arrays for each unique number
    map<int, vector<int>> prefixSum;
    for(int i = 0; i < n; i++) {
        if(prefixSum.find(a[i]) == prefixSum.end()) {
            prefixSum[a[i]] = vector<int>(n + 1, 0);
        }
        for(auto& p : prefixSum) {
            p.second[i + 1] = p.second[i] + (a[i] == p.first ? 1 : 0);
        }
    }
    
    // Process each query
    for(auto query : queries) {
        int l = query.first, r = query.second;
        bool isGood = true;
        
        // Check if each number appears exactly k times
        for(auto& p : prefixSum) {
            int count = p.second[r] - p.second[l - 1];
            if(count != k) {
                isGood = false;
                break;
            }
        }
        
        if(isGood) {
            result = (result + l) % mod;
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Example test case
    vector<int> arr = {1, 2, 1, 2, 1};
    int k = 2;
    vector<pair<int,int>> queries = {{1, 5}, {2, 4}};
    
    cout << "Method 1 result: " << findGoodSubarrays1(arr, k, queries) << "\n";
    cout << "Method 2 result: " << findGoodSubarrays2(arr, k, queries) << "\n";
    
    return 0;
}
