#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[0]+a[1]<=a[2])
    {
        cout<<a[0]+a[1]<<endl;
    }
    else
    {
        cout<<(a[0]+a[1]+a[2])/2<<endl;
    }
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