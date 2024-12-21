#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    bool z=1;
    for(int& it:a)
    {
        cin>>it;
        if(it!=0)z=0;
    }
    if(z)
    {
        cout<<0<<endl;
        return;
    }
    int F=-1,L=-1;
    for(int i=0;i<n;++i)if(a[i]!=0)
    {
        F=i;
        break;
    }
    for(int i=n-1;~i;--i)if(a[i]!=0)
    {
        L=i;
        break;
    }
    bool ok=1;
    for(int i=F;i<=L;++i)if(a[i]==0)
    {
        ok=0;
        break;
    }
    cout<<(ok?1:2)<<endl;
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