#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    cout<<min(n,k)*min(m,k)<<endl;
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