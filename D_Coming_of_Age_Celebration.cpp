#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),d(n+5,0),b(n,0);
    for(int i=0;i<n;++i)cin>>a[i];
    int res=0;
    for(int j=1;j<=n;++j)
    {
        res+=d[j];
        int tot=a[j-1]+res,mn=min(tot,n-j);
        b[j-1]=tot-mn;
        if(mn>0)
        {
            d[j+1]++;
            if(j+mn+1<=n+1)d[j+mn+1]--;
        }
    }
    for(int i=0;i<n;++i)cout<<b[i]<<(i<n-1?' ':'\n');
}
signed main()
{
    sol(); 
    return 0;
}