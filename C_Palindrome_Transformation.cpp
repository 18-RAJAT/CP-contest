#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,p;
    cin>>n>>p;
    p--;
    string s;
    cin>>s;
    if(n/2<=p)p=n-1-p;
    int ans=0,l=p,r=p;
    for(int i=0;i<n/2;++i)
    {
        int dif=abs(s[i]-s[n-1-i]);
        if(dif>12)dif=26-dif;
        if(dif)ans+=dif,l=min(l,i),r=max(r,i);
    }
    ans+=max(r-l,p-l)+min(r-p,p-l);
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}