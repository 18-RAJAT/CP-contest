#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];
    int l=0,r=1e9;
    int ans=0;
    while(l<r)
    {
        int m=(l+r)>>1;
        int check=0;
        for(int i=0;i<n;++i)
        {
            int temp=a[i]-m;
            if(temp<=0)continue;
            check+=(temp+b[i]-1)/b[i];
        }
        (check<=k)?r=m:l=m+1;
    }
    for(int i=0;i<n;++i)
    {
        int temp=a[i]-l;
        if(temp<=0)continue;
        int checker=(temp+b[i]-1)/b[i];
        ans+=checker*(2*a[i]-(checker-1)*b[i])/2;
        k-=checker;
    }
    cout<<k*l+ans<<endl;
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