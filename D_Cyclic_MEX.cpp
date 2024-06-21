#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000005;
int mex[N],a[N];
bool cycle[N];
void sol()
{
	int n;
	cin>>n;
	for(int i=0;i<2*n;++i)cycle[i]=mex[i]=0;
	for(int i=0;i<n;++i)
    {
		cin>>a[i];
		cycle[a[i]]=1;
		if(i)mex[i]=mex[i-1];
		for(;cycle[mex[i]];)mex[i]++;
	}
	int ans=0;
    for(int i=0;i<n;++i)
    {
        int sum=accumulate(mex+i,mex+n+i,0ll);
		ans=max(ans,sum);
		auto lb=lower_bound(mex+i,mex+n+i,a[i])-mex;
		for(int j=lb;j<n+i;++j)
        {
			sum-=mex[j],mex[j]=a[i],sum+=mex[j];
		}
		mex[i+n]=n,sum-=mex[i],sum+=mex[i+n];
	}
	cout<<ans<<endl;
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