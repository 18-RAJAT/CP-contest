#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cout<<(i&1)?"0":"1";
    }
}
signed main()
{
    sol();
    return 0;
}