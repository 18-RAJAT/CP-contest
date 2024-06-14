#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n+1);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=1;
    for(int i=0;i<n+1;++i)
    {
        cin>>b[i];
        if(n!=i)ans+=abs(a[i]-b[i]);
    }
    int dec=1e15;
    for(int i=0;i<n;++i)
    {
        dec=min({dec,abs(a[i]-b[n]),abs(b[i]-b[n])});
        if(b[n]>=min(a[i],b[i]) && b[n]<=max(a[i],b[i]))
        {
            cout<<ans<<endl;
            return;
        }
    }
    cout<<ans+dec<<endl;
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