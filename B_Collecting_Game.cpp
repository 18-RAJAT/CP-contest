#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<array<int,2>>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i][0];//value of the element
        a[i][1]=i;//index of the element
    }
    sort(a.begin(),a.end());//,greater<array<int,2>>());
    for(int i=1;i<n;++i)
    {
        a[i][0]+=a[i-1][0];//prefix sum
    }
    vector<int>ans(n,0),dp(n,0);
    for(int i=1;i<n;++i)
    {
        if(a[i][0]<=2*a[i-1][0])//if the sum of the first i-1 elements is greater than or equal to the sum of the remaining elements
        {
            dp[i]=1;//then we can make the sum of the first i elements greater than or equal to the sum of the remaining elements
        }
    }
    int suffix_sum=0;
    for(int i=n-1;i>=0;--i)
    {
        ans[a[i][1]]=suffix_sum+i;//the sum of the remaining elements is i
        suffix_sum+=dp[i];//state transition from i to i-1
        //check
        int &prune=dp[i];
        if(~prune)
        {
            prune;
        }
        if(dp[i]==0)
        {
            suffix_sum=0;
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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