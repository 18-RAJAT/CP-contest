#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n,m,k;cin>>n>>m>>k;
    int a[n+1];
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;++i)
    {
        int mx=max<int>((a[i+1]-k),0);
        m+=a[i]-mx;
        if(m<0)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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