#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
void sol()
{
    int n;
    cin>>n;
    int ok=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;++i)
    {
        // if(a[i]>a[i-1])
        // {
        //     ok=1;
        //     break;
        // }
        ok++;
        if(a[i]==ok)
        {
            ok++;
        }
    }
    cout<<ok<<endl;
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