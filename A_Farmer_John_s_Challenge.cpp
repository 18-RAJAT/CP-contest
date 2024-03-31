#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    if(n==k)
    {
        for(int i=0;i<n;++i)
        {
            cout<<1<<" ";
        }
        cout<<endl;
    }
    else if(k==1)
    {
        for(int i=1;i<=n;++i)
        {
            cout<<i<<" ";
        }
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