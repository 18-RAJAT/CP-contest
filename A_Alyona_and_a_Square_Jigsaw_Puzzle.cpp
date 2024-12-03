#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int ans=0,sum=0,x=1,y=1;
    for(int i=0;i<n;++i)
    {
        sum+=a[i];
        while(sum>=y)
        {
            sum-=y;
            x++;
            y=8*(x-1);
        }
        if(sum==0)ans++;
    }
    cout<<ans<<endl;
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