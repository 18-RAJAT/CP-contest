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
    int ans=0,cur=0;
    sort(a,a+n);
    for(int i=0;i<n;++i)
    {
        while(cur<n && a[cur]-a[i]<=5)
        {
            cur++;
        }
        ans=max(ans,cur-i);
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}