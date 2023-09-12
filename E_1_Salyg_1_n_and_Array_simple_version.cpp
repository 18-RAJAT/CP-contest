#include<bits/stdc++.h>
using namespace std;
#define int long long
int query(int x)
{
    int ans;
    cout<<"? "<<x<<endl;
    cin>>ans;
    return ans;
    cout.flush();
}
void sol()
{
    int n,k;
    cin>>n>>k;
    int r=n%k,ok=0,ans=0;
    for(int i=r+1;i<=n;i+=k)
    {
        int Q=query(i);
        ans^=Q;
        if(r+1==i)
        {
            ok=Q;
        }
    }
    int current=r;
    while(current>=1)
    {
        int Q=query(current);
        Q^=ok;
        ans^=Q;
        current--;
    }
    cout<<"! "<<ans<<endl;
    cout.flush();
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