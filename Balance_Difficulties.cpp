#include<bits/stdc++.h>
using namespace std;
#define int long long
struct balanceBinarySearch
{
    vector<int>bs;
    int n,x;
    balanceBinarySearch(int n,int x,vector<int>&bs):n(n),x(x),bs(bs){}
    pair<int,vector<int>>balance()
    {
        if(n==1){return {0,bs};}
        int left=0,right=2000000005,ans=right;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            (recur(mid))?ans=mid,right=mid-1:left=mid+1;
        }
        return balance_cost(ans);
    }
private:
    bool recur(int mid)
    {
        int l=bs[0]-mid,r=bs[0]+mid;
        for(int i=1;i<n;++i)
        {
            int lower_bound=max(bs[i]-mid,l),upper_bound=min(bs[i]+mid,r+x);
            if(upper_bound<lower_bound)return false;
            l=lower_bound,r=upper_bound;
        }
        return true;
    }
    pair<int,vector<int>>balance_cost(int ans)
    {
        vector<pair<int,int>>Adj(n);
        Adj[0]={bs[0]-ans,bs[0]+ans};
        for(int i=1;i<n;++i)
        {
            int lower_bound=max(bs[i]-ans,Adj[i-1].first),upper_bound=min(bs[i]+ans,Adj[i-1].second+x);
            Adj[i]={lower_bound,upper_bound};
        }
        vector<int>cost(n);
        cost[n-1]=Adj[n-1].second;
        for(int i=n-2;~i;--i)
        {
            cost[i]=min(Adj[i].second,cost[i+1]);
            cost[i]=max(cost[i],Adj[i].first);
        }
        int BinarySearchOnAns=0;
        for(int i=0;i<n;++i)
        {
            BinarySearchOnAns=max(BinarySearchOnAns,abs(cost[i]-bs[i]));
        }
        return {BinarySearchOnAns,cost};
    }
};
void sol()
{
    int n,x;
    cin>>n>>x;
    vector<int>bs(n);
    for(int i=0;i<n;++i)
    {
        cin>>bs[i];
    }
    balanceBinarySearch BalancedBinarySearch(n,x,bs);
    auto print=[&](vector<int>& search_idx)
    {
        for(auto it=search_idx.begin();it!=search_idx.end();++it)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    };
    pair<int,vector<int>>ans=BalancedBinarySearch.balance();
    vector<int>S=ans.second;
    cout<<ans.first<<endl;
    print(S);
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