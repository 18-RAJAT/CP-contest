#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],b[100005];
void sol()
{
    int n;
    cin>>n;
    bool ok=true;
    for(int i=0;i<n;++i)a[i]=0;
    for(int i=1;i<n;++i)
    {
        cin>>b[i];
        a[i-1]|=b[i],a[i]|=b[i];
    }
    for(int i=1;i<n;++i)
    {
        if((a[i-1]&a[i])!=b[i])ok=false;
    }
    if(ok)
    {
        for(int i=0;i<n;++i)cout<<a[i]<<" ";
        cout<<endl;
    }
    else
    {
        cout<<-1<<endl;
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