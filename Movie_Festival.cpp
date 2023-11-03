#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i].second>>a[i].first;
    }
    sort(a.begin(),a.end());
    int ans=0;
    int last=0;
    for(int i=0;i<n;++i)
    {
        if(last<=a[i].second)
        {
            ans++;
            last=a[i].first;
        }
        else
        {
            last=min(last,a[i].first);//This is the key step
        }
    }
    cout<<ans<<"\n";
}
signed main()
{
    sol();
    return 0;
}