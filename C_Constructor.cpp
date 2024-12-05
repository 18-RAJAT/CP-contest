#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Part
{
    int j,k;
};
int n,mmin,mmax;
vector<Part>arr;
bool sets(int sets)
{
    vector<int>dp(mmax+1,0);
    dp[0]=1;
    for(int i=0;i<n;++i)
    {
        int max_arr=min(arr[i].k/sets,100000LL);
        for(int j=mmax;~j;--j)
        {
            for(int k=1;k<=max_arr&&j>=k*arr[i].j;++k)
            {
                if(dp[j-k*arr[i].j])dp[j]=1;
            }
        }
    }
    for(int j=mmin;j<=mmax;++j)
    {
        if(dp[j])return true;
    }
    return false;
}
void sol()
{
    cin>>n>>mmin>>mmax;
    arr.resize(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i].j>>arr[i].k;
    }
    int left=0,right=1e12,ans=0;
    while(left<=right)
    {
        int mid=(left+right)/2;
        (sets(mid)?ans=mid,left=mid+1:right=mid-1);
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}