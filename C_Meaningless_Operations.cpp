#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int ans=1;
    if(__builtin_popcount(n+1)==1)
    {
        for(int i=2;i<=sqrt(n);++i)
        {
            if(n%i==0)
            {
                cout<<n/i<<endl;
                return;
            }
        }
        cout<<1<<endl;
        return;
    }
    while(ans<=n)ans*=2;
    cout<<ans-1<<endl;
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