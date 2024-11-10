#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int l,r,k;
    cin>>l>>r>>k;
    cout<<max(0LL,r/k-l+1)<<endl;
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