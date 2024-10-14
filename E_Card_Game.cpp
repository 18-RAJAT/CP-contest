#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int ways(int n,int m)
{
    int ans=1;
    for(int i=0;i<m/2;++i)ans=(ans*(n+i))%MOD;
    for(int i=0;i<m/2;++i)ans=(ans*(n+m/2-1-i))%MOD;
    return ans/2;
}
void sol()
{
    int n,m;
    cin>>n>>m;
    cout<<ways(n,m)<<endl;
}
signed main()
{
    sol();
    return 0;
}