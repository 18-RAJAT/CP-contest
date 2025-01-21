#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<m;++i)
    {
        int t,k,d;
        cin>>t>>k>>d;
        int cnt=0;
        for(int j=0;j<n;++j)if(a[j]<t)cnt++;
        if(cnt<k)
        {
            cout<<-1<<endl;
            continue;
        }
        int ans=0;
        for(int j=0;j<n && k>0;++j)
        {
            if(a[j]<t)ans+=j+1,a[j]=t+d-1,k--;
        }
        cout<<ans<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}