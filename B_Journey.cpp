#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int tot=a+b+c,div=n/tot;
    if(n%tot==0)div--;
    if(div<0)div=0;
    int mul=div*tot,ans=div*3;
    array<int,3>dist={a,b,c};
    for(int i=0;i<3;++i)
    {
        mul+=dist[i],ans++;
        if(mul>=n)break;
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