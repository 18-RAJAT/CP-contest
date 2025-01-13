#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k,l;
    cin>>n>>k>>l;
    k*=2,l*=2;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        a[i]*=2;
    }
    int ans=a[0],tmp=k;
    for(int i=1;i<n;++i)
    {
        if(tmp>=l)
        {
            cout<<ans<<endl;
            return;
        }
        if(ans+a[i]<=tmp)
        {
            tmp=a[i]+ans+k;
            continue;
        }
        int rem=a[i]-ans;
        if(rem>=tmp)
        {
            ans+=(rem-tmp)/2,tmp=(rem+tmp)/2+k;
            continue;
        }
        tmp+=k;
    }
    if(tmp>=l)
    {
        cout<<ans<<endl;
        return;
    }
    cout<<ans+(l-tmp)<<endl;
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