#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,d,s;
    cin>>n>>d>>s;
    n/=s,d/=s;
    if(n==1)
    {
        cout<<s;
        return;
    }
    int ans=min(n,d+1);
    for(int i=2;i*i<=n;++i)
    {
        int pos=i-1,mn=min(n/i,d/pos);
        ans=max(i*mn,ans);
    }
    cout<<s*ans;
}
signed main()
{
    sol();
    return 0;
}