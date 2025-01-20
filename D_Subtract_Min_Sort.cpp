#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i+1<n;++i)
    {
        if(a[i]<=a[i+1])
        {
            a[i+1]-=a[i],a[i]=0;
        }
        else
        {
            a[i]-=a[i+1],a[i+1]=0;
        }
    }
    bool ok=1;
    for(int i=0;i+1<n;++i)
    {
        if(a[i]>a[i+1])
        {
            ok=0;
            break;
        }
    }
    cout<<(ok?"YES":"NO")<<endl;
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