#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    if(n==1)
    {
        cout<<0<<endl;
        return;
    }
    k--;
    int ans=0;
    while(n>=2)
    {
        n-=k;
        ans ++;
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