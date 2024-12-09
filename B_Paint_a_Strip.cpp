#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    map<int,int>mp;
    int m=1,ans=1;
    mp[m]=ans;
    while(m<n)
    {
        m=m*2+2;
        mp[m]=++ans;
    }
    cout<<mp.lower_bound(n)->second<<endl;
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