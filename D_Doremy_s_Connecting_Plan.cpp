#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,c;
    cin>>n>>c;
    int a[n+1];
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    int curr=a[1],tmp=a[1];
    bool ok=false;
    for(int i=2;i<=n;++i)
    {
        tmp+=a[i];
        if(curr+a[i]>=c*i)
        {
            curr=tmp;
            if(i==n)
            {
                ok=true;
            }
        }
    }
    cout<<(ok?"Yes":"No")<<"\n";
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