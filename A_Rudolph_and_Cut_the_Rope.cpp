#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long n;
    cin>>n;
    long long ans=0;
    for(long long i=1;i<=n;++i)
    {
        long long a,b;
        cin>>a>>b;
        if(b<a)
        {
            ans++;
        }
    }
    cout<<ans<<"\n";
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