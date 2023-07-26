#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sol()
{
    int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int x=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int y=(a[i]^x)&(a[j]^x);
			if(y==x)
			{
				cout<<i+1<<" "<<j+1<<" "<<x<<"\n";
				return;
			}
		}
	}
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