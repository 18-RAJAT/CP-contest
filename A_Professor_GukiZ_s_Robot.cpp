#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<(max(abs(a-c),abs(b-d)));
}
signed main()
{
    sol();
    return 0;
}