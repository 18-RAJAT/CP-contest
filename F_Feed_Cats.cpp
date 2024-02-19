#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>left(m),right(m);
    for(int i=0;i<m;++i)
    {
        cin>>left[i]>>right[i];
    }
    int count=0;
    vector<int>dp(n+1,0),prefix(n+1,0);
    vector<vector<int>>start(n+1),end(n+2);
    map<int,int>mp;
    for(int i=0;i<m;++i)
    {
        end[right[i]+1].push_back(left[i]);
        start[left[i]].push_back(right[i]);
    }
    for(int i=1;i<=n;++i)
    {
        for(auto& it:start[i])
        {
            mp[i]++;
            count++;
        }
        for(auto& it:end[i])
        {
            mp[it]--;
            count--;
            if(mp[it]==0)
            {
                mp.erase(it);
            }
            count--;
        }
        if(mp.empty())
        {
            dp[i]=prefix[i-1];
        }
        else
        {
            //find the maximum number of elements that can be removed from the array such that the sum of the remaining elements is maximum and the removed elements are from the prefix of the array
            int cost=count;
            cost+=prefix[mp.begin()->first-1];
            dp[i]=max(prefix[i-1],cost);
        }
        prefix[i]=max(prefix[i-1],dp[i]);
    }
    mp.clear();
    cout<<*max_element(prefix.begin(),prefix.end())<<endl;

}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}