#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll>a(n);
		a.resize(n-1);
		for(ll i=0;i<n-1;++i)
		{
			cin>>a[i];
		}
		vector<ll>b={a[0]};
		for(ll i=1;i<n-1;++i)
		{
			b.push_back(a[i]-a[i-1]);
		}
		multiset<ll>aa,bb;
		for(auto u:b)
		{
			bb.insert(u);
		}
		for(ll i=1;i<=n;++i)
		{
			if(bb.find(i)!=bb.end())
			{
				bb.erase(bb.find(i));
				aa.insert(i);
			}
		}
		if(bb.empty())
		{
			cout<<"YES\n";
			continue;
		}
		if(bb.size()!=1)
		{
			cout<<"NO\n";
			continue;
		}
		ll sum=0;
		for(ll i=1;i<=n;++i)
		{
			if(aa.find(i)==aa.end())
			{
				sum+=i;
			}
		}
		cout<<(sum!=*bb.begin()?"NO\n":"YES\n");
	}
}