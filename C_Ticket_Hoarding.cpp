#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<pair<int,int>>vp;
    for(int i=0;i<n;++i)
    {
        vp.push_back({a[i],i});
    }
    sort(vp.begin(),vp.end());
    vector<int>ticket(n,0);
    for(int i=0;i<n;++i)
    {
        if(k>=1)
        {
            int Hord=min(m,k);
            ticket[vp[i].second]=Hord;
            k-=Hord;
        }
    }
    int ans=0,ert=0;
    for(int i=0;i<n;++i)
    {
        int cst=(a[i]+ert);
        ans+=(ticket[i]*cst);
        ert+=ticket[i];
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