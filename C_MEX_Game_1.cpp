#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        mp[a[i]]++;
    }
    int ok=0;
    for(int i=0;i<n+2;++i)
    {
        if(mp[i]==0)
        {
            cout<<i<<endl;
            return;
        }
        if(mp[i]==1)
        {
            if(ok==1)
            {
                cout<<i<<endl;
                return;
            }
            ok=1;
        }
    }
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