#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    map<int,int>home,away;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first>>a[i].second;
        home[a[i].first]++;
        away[a[i].second]++;
    }
    for(int i=0;i<n;++i)
    {
        cout<<n-1+home[a[i].second]<<" "<<n-1-home[a[i].second]<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}