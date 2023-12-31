#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    int mn=INT_MAX,mx=INT_MIN;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
    }
    int x=0,y=0;
    for(int i=0;i<n;++i)
    {
        x+=(a[i]==mn)?1:0;
        y+=(a[i]==mx)?1:0;
    }
    if(mn==mx)
    {
        cout<<0<<" "<<(n*(n-1))/2;
    }
    else
    {
        cout<<mx-mn<<" "<<x*y;
    }
}
signed main()
{
    sol();
    return 0;
}