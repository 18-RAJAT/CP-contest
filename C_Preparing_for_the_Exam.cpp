#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(m);
    for(auto &x:a)cin>>x;
    vector<int>q(k);
    for(auto &x:q)cin>>x;
    string ans;
    if(k<n-1) ans.assign(m,'0');
    else if(k==n) ans.assign(m,'1');
    else
    {
        int ok=0,cnt=0;
        for(int i=1;i<=n;++i)
        {
            if(cnt<k && q[cnt]==i)cnt++;
            else
            {
                ok=i;
                break;
            }
        }
        if(ok==0)ok=n;
        for(auto &x:a)
        {
            if(x==ok)ans+='1';
            else ans+='0';
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