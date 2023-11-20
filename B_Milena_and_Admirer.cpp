#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int last=v[n-1];
    int ans=0;
    for(int i=n-2;i>=0;--i)
    {
        if(v[i]<=last)
        {
            last=v[i];
            continue;
        }
        if(v[i]%last==0)
        {
            ans+=v[i]/last-1;
            // last=v[i]/last;
            continue;
        }
        ans+=v[i]/last;
        last=v[i]/(1+v[i]/last);
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