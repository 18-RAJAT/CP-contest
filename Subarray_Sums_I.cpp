#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    int a[n];
    memset(a,0,sizeof(a));
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=0;
    int sum=0;
    int i=0;
    for(int j=0;j<n;++j)
    {
        sum+=a[j];
        while(sum>x)
        {
            sum-=a[i];
            i++;
        }
        if(sum==x)
        {
            ans++;
        }
    }
    cout<<ans<<"\n";
}
signed main()
{
    sol();
    return 0;
}