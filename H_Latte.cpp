#include <bits/stdc++.h>
using namespace std;
#define int long long
int count(int n)
{
    if(n==0)return 1;
    return(log10(n))+1;
}
bool calc(int n, int a, int b, int x)
{
    return a*n+b*count(n)<=x;
}
void sol()
{
    int a,b,x;
    cin>>a>>b>>x;
    int l=0,r=1e9,ans=0;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        (calc(mid,a,b,x)?ans=mid,l=mid+1:r=mid-1);
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}