#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{

    int x,y,n;
    cin>>x>>y>>n;
    vector<int>a(n+1);
    a[n]=y;
    int ans=1;
    for(int i=n-1;i>=1;--i)
    {
        a[i]=a[i+1]-ans;
        ans++;
    }
    if(a[1]<x)
    {
        cout<<-1<<endl;
    }
    else
    {
        a[1]=x;
        // cout<<a[1]<<endl;
        for(int i=1;i<=n;++i)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
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