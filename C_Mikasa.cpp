#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int i=31;~i && n<=m;--i)
    {
        int bit1=n>>i&1,bit2=(m+1)>>i&1;
        if(bit1!=bit2)
        {
            if(n|(1<<i)<=m+1)ans+=1<<i;
            n|=1<<i;
        }
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