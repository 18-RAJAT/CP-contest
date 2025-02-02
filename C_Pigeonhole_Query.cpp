#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>p(n+1),c(n+1,1);
    int ans=0;
    for(int i=1;i<=n;++i)p[i]=i;
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x,y;
            cin>>x>>y;
            int z=p[x];
            p[x]=y,c[z]--;
            if(c[z]==1)ans--;
            c[y]++;
            if(c[y]==2)ans++;
        }
        else
        cout<<ans<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}