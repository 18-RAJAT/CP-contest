#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long n,b,h;
    cin>>n>>b>>h;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    long double ans=(b*h*(long double)(n))/2.0;
    for(int i=n-2;i>=0;--i)
    {
        long double tp=h-(a[i+1]-a[i]);
        if(tp>0)
        {
            long double nw=b*(tp/h);
            ans-=(nw*tp)/2.0;
        }
    }
    cout<<fixed<<setprecision(15)<<ans<<"\n";
}
int main()
{
	int t;
	cin>>t;
	while(t-->0)
	{
        sol();
	}
	return 0;
}