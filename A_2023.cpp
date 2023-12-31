#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ok=1;
    for(int i=0;i<n;++i)
    {
        ok*=a[i];
        if(2023<ok)
        {
            cout<<"NO";
            return;
        }
    }
    if(2023%ok)
    {
        cout<<"NO";
        return;
    }
    cout<<"YES\n"<<2023/ok<<" ";
    for(int i=0;i<k-1;++i)
    {
        cout<<1<<" ";
    }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
        cout<<endl;
    }
    return 0;
}