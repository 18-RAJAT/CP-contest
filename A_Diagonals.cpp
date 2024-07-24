#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    if(k==0)
    {
        cout<<0<<endl;
        return;
    }
    int ans=1;
    k-=n;
    int ele=n-1;
    for(;k>=1;)
    {
        k-=ele;
        ans++;
        if(k<=0)break;
        k-=ele,ans++,ele--;
    }
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