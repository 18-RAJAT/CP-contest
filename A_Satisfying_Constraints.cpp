#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>chk;
    int mx=1e9,mn=1;
    int a,x;
    for(int i=1;i<=n;++i)
    {
        cin>>a>>x;
        if(a==1)
        {
            mn=max(mn,x);
        }
        else if(a==2)
        {
            mx=min(mx,x);
        }
        else
        {
            chk.push_back(x);
        }
    }
    if(mx<mn)
    {
        cout<<0<<endl;
        return;
    }
    int get=mx-mn+1;
    for(auto& it:chk)
    {
        if(it>=mn&&it<=mx)
        {
            get--;
        }
    }
    cout<<get<<endl;
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