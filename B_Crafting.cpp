#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]<b[i])
        {
            int rem=b[i]-a[i];
            a[i]+=2*rem,ans+=rem;
        }
    }
    int ok=1;
    for(int i=0;i<n;++i)
    {
        a[i]-=ans;
        if(a[i]<0 || a[i]<b[i])ok=0;
    }
    cout<<((ok)?"YES":"NO")<<endl;
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