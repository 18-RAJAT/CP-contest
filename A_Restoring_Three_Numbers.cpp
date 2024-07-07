#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a[4];
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	sort(a,a+4);
	cout<<a[3]-a[0]<<" "<<a[3]-a[1]<<" "<<a[3]-a[2]<<" ";
}
signed main()
{
    sol();
    return 0;
}