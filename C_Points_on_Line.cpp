#include<bits/stdc++.h>
using namespace std;

	int main()
	{
		long long int n,d;
        cin>>n>>d;

        long long int a[n+1];
        memset(a,0,sizeof(a));

        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        long long int ans=0;
        for(int i=0;i<n;++i)
        {
            long long int bound=upper_bound(a,a+n,a[i]+d)-a;
            bound-=i+1;
            ans+=bound*(bound-1)/2;
        }
        cout<<ans<<"\n";
    }