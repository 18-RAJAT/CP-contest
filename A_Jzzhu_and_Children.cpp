#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    double m;
    cin>>m;
    vector<int>a(n+1);
    int res=0,ans=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        int value=ceil(a[i]/m);
        if(value>=res)res=value,ans=i;
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}