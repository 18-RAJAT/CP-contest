#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=n;i<=n+100;++i)
    {
        int sum=0;
        int temp=i;
        while(temp)
        {
            sum+=temp%10;
            temp/=10;
        }
        if(sum%k==0)
        {
            ans=i;
            break;
        }
    }
    cout<<ans<<"\n";
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