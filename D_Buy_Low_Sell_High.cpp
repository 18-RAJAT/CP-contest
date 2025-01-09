/*

| Day | Stock | Price | Share | Profit |
|-----|-------|-------|-------|--------|
| 1   | -     | 10    | 0     | 0      |
| 2   | Buy   | 5     | 1     | 0      |
| 3   | Buy   | 4     | 2     | 0      |
| 4   | -     | 7     | 2     | 0      |
| 5   | Sell  | 9     | 1     | 5      |
| 6   | Sell  | 12    | 0     | 12     |
| 7   | -     | 6     | 0     | 12     |
| 8   | Buy   | 2     | 1     | 12     |
| 9   | Sell  | 10    | 0     | 20     |

*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int ans=0;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(auto& it:a)
    {
        if(!pq.empty() && pq.top()<it)
        {
            ans+=it-pq.top();
            pq.pop();
            pq.push(it);
        }
        pq.push(it);
    }
    cout<<abs(ans)<<endl;
}
signed main()
{
    sol();
    return 0;
}