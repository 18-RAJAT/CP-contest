#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int permutation=1;
    for(int i=1;i<=n;++i)
    {
        permutation=(permutation*i)%1000000007;
    }
    int cyclic_permutation=1;
    for(int i=1;i<n;++i)
    {
        cyclic_permutation=(cyclic_permutation*2)%1000000007;
    }
    int ans=(permutation-cyclic_permutation+1000000007)%1000000007;
    cout<<ans%1000000007;
}
signed main()
{
    sol();
    return 0;
}