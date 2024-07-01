#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=INT_MAX/2;
void Take(vector<int>& a,int n)
{
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        a[x]++;
    }
}

void recur(const vector<int>& a,vector<int>& ndp,int n)
{
    for(int i=1;i<=n;++i)
    {
        if(a[i]>=1)ndp.push_back(a[i]);
    }
}

void computeDP(const vector<int>& ndp,vector<int>& dp)
{
    int m=ndp.size();
    for(int i=0;i<m;++i)
    {
        auto temp_dp_check=dp;
        for(int j=0;j<i;++j)
        {
            if(dp[j]+ndp[i]<=i-j)
            {
                temp_dp_check[j+1]=min(temp_dp_check[j+1],dp[j]+ndp[i]);
            }
        }
        dp.swap(temp_dp_check);
    }
}

int total_compute(const vector<int>& dp,int m)
{
    int ans=MAX;
    for(int i=0;i<=m;++i)
    {
        if(dp[i]<MAX/2)ans=min(ans,m-i);
    }
    return ans;
}

void sol()
{
    int n;
    cin>>n;
    vector<int>a(n+1);
    Take(a,n);
    vector<int>ndp;
    recur(a,ndp,n);
    int m=ndp.size();
    vector<int>dp(m+1,MAX);
    dp[0]=0;
    computeDP(ndp,dp);
    cout<<total_compute(dp,m)<<endl;
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