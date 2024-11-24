#include<bits/stdc++.h>
using namespace std;
#define int long long

const int INF=LLONG_MAX;
const int N=12;
int n,cube[N][N][N];
struct State
{
    int cost,x,mask;
    bool operator<(const State&other)const{return cost>other.cost;}
};

void sol()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int k=0;k<n;++k)
            {
                cin>>cube[i][j][k];
            }
        }
    }
    priority_queue<State>pq;
    unordered_map<int,int>dp;
    pq.push({0,0,0});
    while(!pq.empty())
    {
        State current=pq.top();
        pq.pop();
        int cur=current.cost,x=current.x,mask=current.mask;
        if(x==n)
        {
            cout<<cur<<endl;
            return;
        }
        if(dp.count(mask) && dp[mask]<=cur)continue;
        dp[mask]=cur;
        for(int i=0;i<n;++i)
        {
            if(mask&(1<<i))continue;
            for(int j=0;j<n;++j)
            {
                if(mask&(1<<(j+n)))continue;
                int newMask=mask|(1<<i)|(1<<(j+n));
                int newCost=cur+cube[x][i][j];
                pq.push({newCost,x+1,newMask});
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sol();
    return 0;
}