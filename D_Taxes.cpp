#include<bits/stdc++.h>
using namespace std;
#define int long long
bool prime(int n)
{
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)return false;
    }
    return true;
}
void sol()
{
    int n;
    cin>>n;
    if(prime(n))cout<<1;
    else if(n%2==0 || prime(n-2))cout<<2;
    else cout<<3;
}
signed main()
{
    sol();
    return 0;
}