#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);

    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    if(k==4)
    {
        vector<int>b(n);
        for(int i=0;i<n;++i)
        {
            b[i]=a[i]&1;
        }
        // sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int ans=b[0]+b[1];
        for(int i=0;i<n;++i)
        {
            int res=k-(a[i]%k);
            res%=k;
            ans=min(ans,res);
        }
        cout<<ans<<"\n";
    }
    else
    {
        int ans=k+1;
        for(int i=0;i<n;++i)
        {
            int res=k-(a[i]%k);
            res%=k;
            // ans+=res;
            ans=min(ans,res);
        }
        cout<<ans<<"\n";
    }
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