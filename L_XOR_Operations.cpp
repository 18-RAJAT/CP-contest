#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    bitset<30>bs,xor_sum;
    for(int i=0;i<n;++i)
    {
        bs|=a[i];
        xor_sum^=a[i];
    }
    int ans=1;
    for(int i=0;i<30;++i)
    {
        if(bs[i])
        {
            ans=(ans*2)%998244353;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}