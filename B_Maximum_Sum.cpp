#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Mod 1000000007
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    int res=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        res+=a[i];
    }
    int sum=0,ans=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]>=0 && sum<0)
        {
            sum=0;
        }
        sum+=a[i];
        ans=max(ans,sum);
    }
    res-=ans;
    for(int i=0;i<k;++i)
    {
        ans*=2,ans%=Mod;
    }
    if(res<0)res+=((abs(res)/Mod+1)*Mod);
    res+=ans,cout<<res%Mod<<endl;
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