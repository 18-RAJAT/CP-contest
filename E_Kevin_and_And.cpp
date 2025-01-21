#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=12,M=1e5+5;
void sol()
{
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    int a[n],b[m],dp[n][N],temp[n];
    vector<int>ar[N];
    priority_queue<array<int,2>>pq;
    for(int i=0;i<n;++i)cin>>a[i],ans+=a[i];
    for(int i=0;i<m;++i)cin>>b[i];
    for(int i=0;i<m;++i)ar[i].clear();
    auto right=[&](int x,int y)->int
    {
        return (x>>y)&1;
    };
    auto left=[&](int x,int y)->int
    {
        return x^(1<<y);
    };
    for(int i=0;i<(1<<m);++i)
    {
        int bit=-1,cnt=0;
        for(int j=0;j<m;++j)
        {
            if(right(i,j))bit&=b[j],cnt++;
        }
        // cout<<bit<<" "<<cnt<<endl;
        ar[cnt].push_back(bit);
    }
    for(int i=0;i<n;++i)
    {
        temp[i]=1;
        // for(int j=0;j<N;++j)dp[i][j]=1e9;
        memset(dp[i],0x3f,sizeof dp[i]);
        for(int j=0;j<=m;++j)
        {
            for(auto& it:ar[j])
            {
                dp[i][j]=min(dp[i][j],a[i]&it);
                //cout<<dp[i][j]<<" ";
                // if(left(a[i],j)==it)dp[i][j]=min(dp[i][j],a[i]);
            }
        }
        pq.push({dp[i][0]-dp[i][1],i});
    }
    while(k--)
    {
        int v=pq.top()[0],i=pq.top()[1];
        pq.pop();
        ans-=v;//minimize [i][0]-[i][1]
        if(temp[i]<m)
        {
            pq.push({dp[i][temp[i]]-dp[i][temp[i]+1],i});
            temp[i]++;
        }
    }
    
    cout<<ans<<endl;
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