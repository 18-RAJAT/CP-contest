#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if((n/2)&1)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES"<<endl;
        int ans=0,sum=0;
        for(int j=0;j<=n/2-1;++j)
        {
            ans+=2,sum+=ans;
            cout<<ans<<" ";
        }
        ans=1;
        int tmp=0;
        for(int j=n/2;j<n-1;++j)
        {
            tmp+=ans;
            cout<<ans<<" ";
            ans+=2;
        }
        cout<<sum-tmp;
    }
    cout<<endl;
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