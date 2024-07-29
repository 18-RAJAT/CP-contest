#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
void sol()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(i%2==0)ans=max(ans,a[i]);
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