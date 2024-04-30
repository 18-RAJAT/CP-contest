#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>p(n);
    int ok=0;
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        cin>>p[i];
        mp[p[i]]=i+1;
        if(mp[i+1]==p[i])
        {
            ok=1;
        }
    }
    cout<<((ok)?2:3)<<endl;
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