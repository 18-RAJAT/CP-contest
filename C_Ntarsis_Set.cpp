#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,k;cin>>n>>k;
		vector<long long>a(n);
		a.resize(n+1);

		for(long long i=1;i<=n;i+=1)
		{
			cin>>a[i];
			a[i]-=(i-1);
		}
		long long pos=1;
		for(long long i=1;i<=k;i+=1)
		{
			long long find=upper_bound(a.begin()+1,a.end(),pos)-a.begin()-1;
			pos+=find;
		}
		cout<<pos<<"\n";
    }
}