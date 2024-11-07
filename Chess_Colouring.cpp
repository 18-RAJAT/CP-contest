#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
void sol()
{
    int n;
    cin>>n;
    int IN=500000004;
    if(n%2==0)cout<<2<<endl;
    else
    {
        // int P=(n%MOD)*(n%MOD)%MOD;
        // int Q=(P*IN)%MOD;
        // int R=(3*IN)%MOD;
        // cout<<(Q+R)%MOD<<endl;
        cout<<(n*n+3)/2<<endl;
    }
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