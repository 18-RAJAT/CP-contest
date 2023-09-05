#include<bits/stdc++.h>
using namespace std;
#define int long long
int days(int n,int m,int k)
{
    int mn=min<int>(m,k);
    int calc=k-mn;
    return ((n-mn-calc*(calc+1)/2))<=0?0:1;
}
signed main()
{
    int n,m;
    cin>>n>>m;   
    int start=1,end=INT_MAX,ans=1;
    while(start<=end)
    {
    	int mid=start+(end-start)/2;
    	if(days(n,m,mid)<=0)
    	{
    		ans=mid;
    		end=mid-1;
    	}
    	else
    	{
    		start=mid+1;
    	}
    }
    cout<<ans;
    return 0;
}