#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<int>prefix(n,0),suffix(n,0);
    for(int i=1;i<n;++i)
    {
        prefix[i]=prefix[i-1];
        if(a[i]>=a[i-1])
        {
            prefix[i]++;
        }
    }
    for(int i=n-2;i>=0;--i)
    {
        suffix[i]=suffix[i+1];
        if(a[i]>=a[i+1])
        {
            suffix[i]++;
        }
    }
    int ans=prefix[0]+suffix[0];
    for(int i=1;i<n;++i)
    {
        ans=min<int>(ans,prefix[i-1]+suffix[i]+1);
    }
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