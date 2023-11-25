#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    int minimum=1e9;
    int maximum=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        minimum=min(minimum,a[i]);
        maximum=max(maximum,a[i]);
    }
    int ans=1;
    if(minimum==maximum)
    {
        cout<<0<<endl;
        return;
    }
    int average=(minimum+maximum)/2;
    while(average!=minimum)
    {
        ans++;
        average=(average+minimum)/2;
    }
    cout<<ans<<endl;
    if(ans<=n)
    {
        for(int i=0;i<ans;++i)
        {
            cout<<minimum<<" ";
        }
    }
    cout<<endl;
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