#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    cout<<max(n-a,a-1)+max(m-b,b-1)<<endl;
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
