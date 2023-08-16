#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
void sol()
{
	int n,m,d;
	cin>>n>>m>>d;
	vector<int>a,b;
	a.pb(0),a.pb(1);
	b.pb(1),b.pb(n+1);
	for(int i=0;i<m;++i)
	{
		int x;
		cin>>x;
		if(x!=1)
		{
			a.pb(x),b.pb(x);
		}
	}
	// sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int ctr(0),ert(0);
	for(int i=0;i<b.size()-2;++i)
	{
		int c1=3+(b[i+1]-b[i]-1)/d;
		int c2=(b[i+2]-b[i+1]-1)/d;
		int c3=2+(b[i+2]-b[i]-1)/d;
		
		int divs=c1/c2;
		if(c3<divs)
		{
			ctr++;
		}
	}
	for(int i=1;i<a.size();++i)
	{
		ert+=1+(b[i]-b[i-1]-1)/d;
	}
	if(ctr>=1)
	{
		cout<<ert-1<<" "<<ctr<<"\n";
	}
	else
	{
		cout<<ert<<" "<<m<<"\n";
	}
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