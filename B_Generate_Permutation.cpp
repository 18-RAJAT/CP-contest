#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
void sol()
{
    int n;
    cin>>n;
    if(n&1)
    {
        for(int i=n/2+1;i>=1;--i)
        {
            cout<<i<<" ";
        }
        for(int i=n/2+2;i<=n;++i)
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