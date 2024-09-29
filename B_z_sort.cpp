#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int l=0,r=n-1;
    while(l<=r)
    {
        if((l+r)%2==n%2)
        {
            cout<<a[r]<<" "[n==r];
            r--;
        }
        else
        {
            cout<<a[l]<<" "[l==r];
            l++;
        }
    }
}
signed main()
{
    sol();
    return 0;
}