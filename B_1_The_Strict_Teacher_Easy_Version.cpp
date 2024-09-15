#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<int>a(m);
    for(int i=0;i<m;++i)
    {
        cin>>a[i];
    }
    int x;
    cin>>x;
    if(a[0]>a[1])swap(a[0],a[1]);
    if(x<a[0])
    {
        cout<<a[0]-1<<endl;
    }
    else if(a[1]<x)
    {
        cout<<n-a[1]<<endl;
    }
    else
    {
        cout<<(a[1]-a[0])/2<<endl;
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