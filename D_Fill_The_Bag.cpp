#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int res=0,ans=0;
    multiset<int,greater<int>>ms;
    for(int i=1;i<=m;++i)
    {
        int x;
        cin>>x;
        res+=x;
        ms.insert(x);
    }
    if(res<n)cout<<-1<<endl;
    else
    {
        while(n)
        {
            int beg=*ms.begin();
            ms.erase(ms.begin());
            if(beg<=n)n-=beg,res-=beg;
            else if(res-beg<n)
            {
                ans++;
                ms.insert(beg>>1);
                ms.insert(beg>>1);
            }
            else res-=beg;
        }
        cout<<ans<<endl;
    }
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