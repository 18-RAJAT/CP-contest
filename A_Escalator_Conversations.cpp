#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sol()
{
    int n,m,k,h;
    cin>>n>>m>>k>>h;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        int x=abs(h-a[i]);
        if((x<m*k)&&(x%k==0)&&(a[i]!=h))
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
	while(t--)
	{
		sol();
    }
}