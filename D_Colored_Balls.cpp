#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[5005];
int dp[5005][5005];
int n;
int add(int x,int y,int mod)
{
    return (((x%mod)+(y%mod))%mod+mod)%mod;
}
int recur(int index=0,int sum=0)
{
    if(index==n)
    {
        return 0;
    }
    int &ans=dp[index][sum];
    if(~ans)return ans;
    int sol=max(arr[index],(sum+arr[index]+1)/2);
    sol=add(sol,recur(index+1,sum),998244353);
    sol=add(sol,recur(index+1,sum+arr[index]),998244353);
    return ans=sol;
}
void sol()
{

    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    fill(&dp[0][0],&dp[0][0]+5005*5005,-1);
    cout<<recur()<<endl;
}
signed main()
{
    sol();
    return 0;
}