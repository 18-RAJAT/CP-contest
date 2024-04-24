#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>>vp(n);
    for(int i=0;i<n;++i)
    {
        cin>>vp[i].first;
        vp[i].second=i;
    }
    sort(vp.begin(),vp.end(),greater<pair<int,int>>());
    vector<int>ans(n);
    int a=1,b=-1;
    int distance=0;
    for(int i=0;i<n;++i)
    {
        if(abs(a)<abs(b))
        {
            distance+=(vp[i].first*(2*abs(a)));
            ans[vp[i].second]=a;
            a++;
        }
        else
        {
            int curr=abs(b);
            distance+=(vp[i].first*(2*curr));
            ans[vp[i].second]=b;
            b--;
        }
    }
    cout<<distance<<endl; 
    cout<<0<<" ";
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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