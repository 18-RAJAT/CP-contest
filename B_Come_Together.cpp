#include<bits/stdc++.h>
using namespace std;
#include <iostream>

void sol()
{
	long long a,b,xy,yx,xx,yy;
	cin>>a>>b>>xy>>yx>>xx>>yy;
	long long ans=0;
	auto func=[&](long long vals)->void
	{
		ans+=vals;
	};
	if((a-xy)*(a-xx)>0=)
	{
		func(min<long long>(abs<long long>(a-xy),abs<long long>(a-xx)));
	}
	if((b-yx)*(b-yy)>=0)
	{
		func(min<long long>(abs<long long>(b-yx),abs<long long>(b-yy)));
	}
	cout<<1+ans<<"\n";
}

int main()
{
    long long t;cin>>t;
    while(t--)
    {
        sol();
    }
}