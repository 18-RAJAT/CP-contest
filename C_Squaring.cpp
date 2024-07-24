#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n],b[n]={};
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=0,mx=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]==1 && mx>=2)ans=-1;mx=max(mx,a[i]);
    }
    if(ans==-1)
    {
        cout<<ans<<endl;
        return;
    }
    for(int i=1;i<n;++i)
    {
        if(a[i]>a[i-1])
        {
            int res=0,temp=a[i-1];
            for(;temp<=a[i] && res<b[i-1]+1;)
            res++,temp*=temp;
            b[i]=b[i-1]-res+1;
        }
        else if(a[i]<a[i-1])
        {
            int res=0,temp=a[i];
            for(;temp<a[i-1];)
            res++,temp*=temp;
            b[i]=b[i-1]+res;
        }
        else
        {
            b[i]=b[i-1];
        }
    }
    for(int i=0;i<n;++i)ans+=b[i];
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