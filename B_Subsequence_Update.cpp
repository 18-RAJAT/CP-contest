#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,l,r;
    cin>>n>>l>>r;
    vector<int>a(n+1),ar,br,ok;
    int sz=r-l+1;
    for(int i=1;i<=n;++i)cin>>a[i];
    int sum1=0,sum2=0;
    for(int i=1;i<=r;++i)ar.push_back(a[i]);
    for(int i=l;i<=n;++i)br.push_back(a[i]);
    sort(ar.begin(),ar.end());
    sort(br.begin(),br.end());
    for(int i=0;i<sz;++i)sum1+=ar[i];
    for(int i=0;i<sz;++i)sum2+=br[i];
    int ans=min<int>(sum1,sum2);
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