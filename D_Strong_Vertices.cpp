#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    vector<pair<int,int>>ans;
    int Strong=INT_MIN;
    for(int i=0;i<n;++i)
    {
        ans.push_back(make_pair(a[i]-b[i],i+1));
        Strong=max<int>(Strong,a[i]-b[i]);
    }
    vector<int>res;
    for(int i=0;i<n;++i)
    {
        if(ans[i].first==Strong)
        {
            res.push_back(ans[i].second);
        }
    }
    cout<<res.size()<<"\n";
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i]<<" ";
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
}