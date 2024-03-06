#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,c;
    cin>>n>>c;
    int a=0,b=0;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        ans+=(c+1)-x;
        ((x&1)?a:b)++,ans+=(x+2)/2,ans-=((x&1)?a:b);
    }
    c++;
    int sum=((c+1)*c)/2;
    cout<<sum-ans<<endl;
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