#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>ans(n+1),ok(n+1,0);
    if(n&1)
    {
        ans[n]=n,ans[n-1]=n-1,ans[n-2]=1,ans[n-3]=3;
    }
    else
    {
        ans[n]=1<<(31-__builtin_clz(n)),ans[n-1]=(1<<(31-__builtin_clz(n)))-1,ans[n-2]=(1<<(31-__builtin_clz(n)))-2,ans[n-3]=1,ans[n-4]=5;
    }
    for(int i=1;i<=n;++i)ok[ans[i]]=1;
    int res=1;
    for(int i=1;i<=n;++i)
    {
        if(ans[i])continue;
        while(ok[res])++res;
        ans[i]=res++;
    }
    int bit=0;
    for(int i=1;i<=n;++i)
    {
        if(i&1)bit&=ans[i];
        else bit|=ans[i];
    }
    cout<<bit<<endl;
    for(int i=1;i<=n;++i)cout<<ans[i]<<" \n"[i==n];
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