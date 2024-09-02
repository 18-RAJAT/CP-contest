#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int l,r;
    cin>>l>>r;
    int ans=r-l;
    if(ans==0)
    {
        cout<<1<<endl;
        return;
    }
    int good=1+sqrtl(2*ans);
    for(;good*(good-1)/2>ans;--good);
    cout<<good<<endl;
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