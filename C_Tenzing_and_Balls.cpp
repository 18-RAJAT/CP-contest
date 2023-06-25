#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long n;cin>>n;
    long long a[n];
    for(long long i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<long long>dp(n+1,LLONG_MAX),search(n+1,LLONG_MAX);
    search[a[0]]=0;
    dp[0]=1;
    // for(long long i=n-1;i>=0;--i)
    for(int i=1;i<n;++i)
    {
        //pruning for i
        // dp[i]=dp[i+1];
        // search[i]=search[i+1];

        // long long chk=i;
        dp[i]=min<long long>(dp[i-1]+1,search[a[i]]);//-i+1);
        
        search[a[i]]=min<long long>(search[a[i]],dp[i-1]);//+i);
        // cout<<search[a[i]]<<" ";//maximize okay
    }
    cout<<(n-dp[n-1])<<"\n";
}
int main()
{
	long long t;
	cin>>t;
	while(t-->0)
	{
        sol();
	}
	return 0;
}