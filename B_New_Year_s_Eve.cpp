#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int cnt=0;
    if(n==1 || k==1)
    {
        cout<<n;
        return;
    }
    while(n>=1)
    {
        cnt++,n/=2;
    }
    cout<<(1LL<<cnt)-1;
}
signed main()
{
    sol();
    return 0;
}