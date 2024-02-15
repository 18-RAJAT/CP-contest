#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+18;
const int INF=1034567891;
int count_triple[N];
int dp[N][3][3];
int n,m;
int func(int index,int c1,int c2)
{
    //Base Case
    if(count_triple[index]-c1-c2<0)
    {
        return -INF;
    }
    //Pruning
    if(index==m+1)//We have reached the end of the array
    {
        return 0;
    }
    int& ans=dp[index][c1][c2];
    //Visited State
    if(~ans)return ans;
    int c3=count_triple[index]-c1-c2;//c3 is the number of triples of index that are not used yet
    int res=-INF;
    //Recurrence Relation + State Transition
    for(int i=0;i<=min(2LL,c3);++i)
    {
        //We can use i triples of index in the current group and the remaining triples will be used in the next group
        res=max(res,i+(c3-i)/3+func(index+1,c2,i));
    }
    //Sanity Check
    // for(int i=0;i<m;++i)
    // {
    //     for(int j=0;j<3;++j)
    //     {
    //         for(int k=0;k<3;++k)
    //         {
    //             assert(dp[i][j][k]>=-INF && dp[i][j][k]<=n);//Range of dp[i][j][k]
    //         }
    //     }
    // }
    //Memoization
    return ans=res;
    //Range of ans
    // assert(ans>=0 && ans<=n);
}
void sol()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        count_triple[x]++;
    }
    memset(dp,-1,sizeof dp);
    cout<<func(0,0,0)<<endl;
}
signed main()
{
    sol();
    return 0;
}