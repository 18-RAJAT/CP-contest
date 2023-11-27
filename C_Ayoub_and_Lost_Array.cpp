#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int dp[N][3];
int n;
int arr[3];
const int mod=1e9+7;
int recur(int i,int cache)
{
    if(i==n)
    {
        return cache==0;
    }
    int &ans=dp[i][cache];
    if(~ans)
    {
        return ans;
    }
    ans=0;
    for(int j=0;j<3;++j)
    {
        ans=(ans+arr[j]*recur(i+1,(cache+j)%3))%mod;
    }
    return ans;
}
void sol()
{
    int l,r;
    cin>>n>>l>>r;
    function<int(int,int)>count=[&](int x,int y)->int
    {
        int check=x%3;
        return x/3+(check>=y);
    };
    for(int i=0;i<3;++i)
    {
        arr[i]=count(r,i)-count(l-1,i);
    }
    memset(dp,-1,sizeof(dp));
    cout<<recur(0,0)<<endl;
}
signed main()
{
    sol();
    return 0;
}