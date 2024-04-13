#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    map<int,int>mp;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    if(mp.size()==1)
    {
        cout<<-1<<endl;
        return;
    }
    int ans=n,count=0;
    int init=a[0];
    for(int i=0;i<n;++i)
    {
        ((a[i]==init)?count++:(ans=min(ans,count),count=0));
    }
    cout<<min(ans,count)<<endl;
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