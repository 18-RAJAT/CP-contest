#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b,c;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]&1)b.push_back(a[i]);
        else c.push_back(a[i]);
    }
    if(b.empty() || c.empty()){cout<<"0"<<endl;return;}
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    int ans=0,cur=0,val=b.back(),ct=c.back(),ert=c.size();
    for(int i=0;i<ert;i++)
    {
        if(val<c[i])
        {
            int interval=(c[i]-val+ct-1)/ct;
            ans+=interval;
            val+=interval*ct;
        }
        val+=c[i],ans++;
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