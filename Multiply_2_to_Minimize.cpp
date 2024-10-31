#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    map<int,int>mp;
    int cur=0;
    vector<int>ans;
    for(int i=0;i<n;++i)
    {
        int tmp=a[i];
        mp[tmp]++,cur++;
        while(mp[tmp]>=2)
        {
            int mul=mp[tmp]/2;
            mp[tmp]%=2,cur-=2*mul,tmp*=2,mp[tmp]+=mul;
            cur+=mul;
        }
        ans.push_back(cur);
    }
    for(int i=0;i<n;++i)
    {
        if(i>=1)cout<<' ';
        cout<<ans[i];
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