#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    n/=k;
    cout<<k*(n+1);
}
signed main()
{
    sol();
    return 0;
}