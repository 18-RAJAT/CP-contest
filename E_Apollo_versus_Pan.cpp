#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    int count[60]={};
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        for(int j=0;j<60;++j)
        {
            count[j]+=(a[i]>>j)&1;
        }
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        int x=0,y=0;
        for(int j=0;j<60;++j)
        {
            if(a[i]>>j&1)
            {
                x=(x+(1LL<<j)%1000000007*count[j])%1000000007;
                y=(y+(1LL<<j)%1000000007*n)%1000000007;
            }
            else
            {
                y=(y+(1LL<<j)%1000000007*count[j])%1000000007;
            }
        }
        ans=(ans+(x*y))%1000000007;
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