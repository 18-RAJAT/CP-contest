#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    if(n>26)cout<<m;
    else cout<<(m&((1<<n)-1));
}
signed main()
{
    sol();
    return 0;
}