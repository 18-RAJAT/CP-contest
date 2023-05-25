#include <iostream>
#include <vector>
#include <algorithm>

long getMaxProfit(const std::vector<int>& pnl, int k) {
    int n = pnl.size();
    std::vector<std::vector<long long>> dp(k + 1, std::vector<long long>(n, 0));
    
    for (int i = 1; i <= k; i++) {
        long long maxDiff = dp[i - 1][0] - pnl[0];
        
        for (int j = 1; j < n; j++) {
            maxDiff = std::max(maxDiff, dp[i - 1][j - 1] - pnl[j - 1]);
            dp[i][j] = std::max(dp[i][j - 1], pnl[j] + maxDiff);
        }
    }
    
    return dp[k][n - 1];
}

int main() {
    std::vector<int> pnl = {7,4,3,-2,9,-4,2,7,6};
    int k = 6;
    
    long maxProfit = getMaxProfit(pnl, k);
    
    std::cout << "Maximum Profit: " << maxProfit << std::endl;
    
    return 0;
}
