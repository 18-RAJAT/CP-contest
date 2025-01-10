#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(m);
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        a[x%m]++;
    }
    int ans=0;
    if(a[0]!=0)ans++;
    for(int i=1;i<m;++i)
    {
        int b=m-i;
        if(b<i)break;
        if(i==b)
        {
            if(a[i]!=0)ans++;
            break;
        }
        if(a[i]==a[b] && a[i]==0)continue;
        else if(a[i]==a[b])ans++;
        else ans+=abs(a[i]-a[b]);
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