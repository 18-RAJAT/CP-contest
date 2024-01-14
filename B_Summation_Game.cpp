#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k,x;
    cin>>n>>k>>x;
    vector<int>a(n);
    int sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int check=0;
    for(int i=0;i<x;++i)
    {
        check+=a[i];
    }
    int ans=sum-(2*check);
    int tmp=x;
    for(int i=0;i<k;++i)
    {
        (n<=tmp?check-=a[i]:check=(check-a[i])+a[tmp],tmp++);
        sum-=a[i];
        ans=max(ans,sum-(2*check));
    }
    // assert(ans>=0);
    cout<<ans<<endl;
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