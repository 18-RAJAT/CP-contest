#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    int ans=1;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        ans=a[i]*ans/__gcd((int)a[i],ans);
    }
    int res=0;
    for(int i=0;i<n;++i)
    {
        b[i]=ans/a[i],res+=b[i];
    }
    if(ans<=res)
    {
        cout<<"-1"<<endl;
        return;
    }
    for(int i=0;i<n;++i)
    {
        b[i]*=n,b[i]++;
        cout<<b[i]<<" ";
    }
    cout<<endl;
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