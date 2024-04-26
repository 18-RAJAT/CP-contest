#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int count=0;
    vector<int>a(n);
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        count=__gcd(a[i],count);
        mp[a[i]]++;
    }
    if(mp[count]>1)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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