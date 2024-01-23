#include<bits/stdc++.h>
using namespace std;
#define int long long
void cache(int index,vector<vector<int>>& arr,vector<int>& check,vector<int>& dp,int n)
{
	int sum=1e18;
	if(dp[index]!=sum)
	{
		return;
	}
	int ans=check[index];
	for(auto val:arr[index])
	{
		cache(val,arr,check,dp,n);
		(sum==1e18)?sum=dp[val]:sum+=dp[val];
	}
	dp[index]=min<int>(ans,sum);
}
void sol()
{
	int n,k;
	cin>>n>>k;
	vector<int>check(n);
	for(int i=0;i<n;++i)
	{
		cin>>check[i];
	}
	vector<int>a(k);
	for(int i=0;i<k;++i)
	{
		cin>>a[i];
		check[a[i]-1]=0;
	}
	vector<vector<int>>arr(n);
	for(int i=0;i<n;++i)
	{
		int m;
		cin>>m;
		for(int j=0;j<m;++j)
		{
			int a;
			cin>>a;
			arr[i].push_back(a-1);
		}
	}
	vector<int>dp(n,1e18);
	for(int i=0;i<n;++i)
	{
		cache(i,arr,check,dp,n);
	}
	for(int i=0;i<dp.size();++i)
	{
		cout<<dp[i]<<" ";
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