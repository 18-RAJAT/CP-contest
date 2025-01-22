#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int l,r,ans=0;
    cin>>l>>r;
    if(l<=1 && r>=1)ans++;
    int start=max(l,2LL);
    if(r-start>=1)ans+=r-start;
    cout<<ans<<endl;
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