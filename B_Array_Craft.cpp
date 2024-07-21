#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x,y;
    cin>>n>>x>>y;
    vector<int>a(n+1);
    for(int i=1;i<y;++i)a[i]=-1;
    for(int i=y;i<=x;++i)a[i]=1;
    int sign=1;
    for(int i=x+1;i<=n;++i)
    {
        (sign==1)?a[i]=-1:a[i]=1,sign^=1;
    }
    sign=1;
    for(int i=y-1;i>=1;--i)
    {
        (sign==1)?a[i]=-1:a[i]=1,sign^=1;
    }
    for(int i=1;i<=n;++i)
    {
        cout<<a[i]<<" \n"[i==n];
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