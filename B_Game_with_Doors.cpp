#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans=0;
    if(d<a && b<c)
    {
        cout<<1<<endl;
        return;
    }
    if(c<a)swap(a,c),swap(b,d);
    int cnt[105]={0};
    int l=-1,r=-1;
    for(int i=a;i<=b;++i)cnt[i]++;
    for(int i=c;i<=d;++i)cnt[i]++;
    for(int i=1;i<105;++i)
    {
        if(cnt[i]==2)
        {
            ans++;
            l=l==-1?i:l,r=i;
        }
    }
    ans-=(l==-1?0:1);
    ans+=(min(a,min(b,min(c,d)))<l)+(max(a,max(b,max(c,d)))>r);
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