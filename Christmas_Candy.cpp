#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int tmp=a[0],ans=0;
    for(int i=1;i<n;++i)
    {
        if(tmp>a[i])
        {
            ans++;
        }
        tmp=max<int>(tmp,a[i]);
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