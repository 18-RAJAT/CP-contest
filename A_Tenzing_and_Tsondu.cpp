#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long n,m;
    cin>>n>>m;
    long long ans1=0,ans2=0;
    long long x;
    for(int i=1;i<=n;++i)
    {
        cin>>x;ans1+=x;
    }
    for(int i=1;i<=m;++i)
    {
        cin>>x;ans2+=x;
    }
    if(ans1==ans2)
    {
        cout<<"Draw\n";
    }
    else
    {
        cout<<((ans2<ans1)?"Tsondu\n":"Tenzing\n");
    }
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