#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int x1=1,x2=1,x3=1,x4=1;
    for(int i=0;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        if(a>0)
        {
            x1=0;
        }
        if(a<0)
        {
            x2=0;
        }
        if(b>0)
        {
            x3=0;
        }
        if(b<0)
        {
            x4=0;
        }
    }
    if(x1 or x2 or x3 or x4)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
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