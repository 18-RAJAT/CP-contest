#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n,k;
    cin>>n>>k;
    int ans=1e9;
    int a[n];
    bool ok[n];
    for(int i=0;i<n;i++)
    {
        ok[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==k)
        {
            cout<<"1\n";
            return 0;
        }
        if(k%a[i]==0)
        {
            ans=min<int>(ans,k/a[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}