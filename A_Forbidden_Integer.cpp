#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		long long n,k,x;
		cin>>n>>k>>x;
		if(x!=1)
		{
			cout<<"YES\n";
			cout<<n<<"\n";
			for(int i=1;i<=n;++i)
			{
				cout<<1<<" ";
			}
			cout<<"\n";
		}
		else if(x==1 && k==1)
		{
			cout<<"NO\n";
		}
		else if(x==1 && n%2 && k==2)
		{
			cout<<"NO\n";
		}
		else if(x==1)
		{
			if(n%2)
			{
				cout<<"YES\n";
				cout<<n/2<<"\n";
				cout<<3<<" ";
				for(int i=0;i<n/2-1;++i)
				{
					cout<<2<<" ";
				}
				cout<<"\n";
			}
			else
			{
				cout<<"YES\n";
				cout<<n/2<<"\n";
				for(int i=0;i<n/2;++i)
				{
					cout<<2<<" ";
				}
				cout<<"\n";
			}
		}
	}
}