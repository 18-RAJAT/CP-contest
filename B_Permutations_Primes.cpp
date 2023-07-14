#include<bits/stdc++.h>
using namespace std;
void sol()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"1\n";
        return;
    }
    if(n==2)
    {
        cout<<"2 1\n";
        return;
    }
    cout<<2<<" ";
    bool ok=0;
    for(int i=1;i<=n-2;++i)
    {
        if(i==n/2)
        {
            ok=1;
            cout<<1<<" ";
        }
        else
        {
            cout<<(3+i)-ok<<" ";
        }
    }
    cout<<3<<" ";
    cout<<"\n";
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
        sol();
	}
	return 0;
}