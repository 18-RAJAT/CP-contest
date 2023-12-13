#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int c[n],a[n],b[n];
    for(int i=0;i<n;++i)
    {
        cin>>c[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    for(int i=0;i<n;++i)
    {
        if(a[i]>b[i])
        {
            swap<int>(a[i],b[i]);
        }
    }
    int ans=0;
    int current=1+c[n-1];
    for(int i=n-1;i>0;--i)
    {
        ans=max<int>(ans,current+(b[i]-a[i]));
        if(a[i]==b[i])
        {
            current=c[i-1]+1;
        }
        else
        {
            current=max<int>(c[i-1]+1,current+2+(a[i]-1)+(c[i-1]-b[i]));
        }
    }
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