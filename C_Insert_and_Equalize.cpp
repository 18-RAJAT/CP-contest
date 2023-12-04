#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
map<int,int>mp;
void sol()
{
    int n;
    cin>>n;
    mp.clear();
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(a.begin(),a.end());
    //base case
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    int ans=0;
    int curr1=a[n-1];
    int curr2=a[n-2];
    int total=curr1-curr2;

    for(int i=n-3;i>=0;--i)
    {
        total=gcd(total,curr1-a[i]);
    }
    // int tmp=0;
    // for(int i=0;i<n;++i)
    // {
    //     tmp=curr1-a[i];
    // }
    for(int i=0;i<n;++i)
    {
        ans+=(curr1-a[i])/total;
    }
    int curr=curr1;
    while(mp.count(curr))
    {
        curr-=total;
    }
    // cout<<curr<<endl;
    ans+=abs(curr1-curr)/total;
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