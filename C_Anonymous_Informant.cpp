#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
void sol()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    bool ok=false;
    int last=n-1;
    int mini=min(n,k);
    for(int i=0;i<mini;++i)
    {
        if(n<a[last])
        {
            ok=true;
            break;
        }
        if(last-a[last]<0)
        {
            last=last-a[last]+n;
        }
        else
        {
            last=last-a[last];
        }
    }
    cout<<((ok==true)?"NO":"YES")<<endl;
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