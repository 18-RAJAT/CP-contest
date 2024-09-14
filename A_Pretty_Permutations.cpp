#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
	if(n%2==0)
    {
		for(int i=2;i<=n;i+=2)
        {
			cout<<i<<" "<<i-1<<" ";
		}
	}
	else
    {
		cout<<"3 1 2";
		for(int j=5;j<=n;j+=2)
        {
			cout<<j<<" "<<j-1<<" ";
		}
	}
	cout<<endl;
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