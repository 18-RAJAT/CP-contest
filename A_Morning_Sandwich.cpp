#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sol()
{
	int b,c,h;
    cin>>b>>c>>h;
    cout<<min<int>(2*b-1,(c+h)*2+1)<<"\n";
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