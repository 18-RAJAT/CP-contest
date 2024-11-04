#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    cout<<(n%7==0?n:(n/7+1)*7);
}
signed main()
{
    sol();
    return 0;
}