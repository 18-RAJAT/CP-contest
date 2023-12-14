#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,d;
    cin>>n>>m>>d;
    pair<int,int>a[n];
    set<int>s;
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first;
        a[i].second=i;
        s.insert(a[i].first);
    }
    int j=1;
    map<int,int>mp;
    while(s.size())
    {
        int beg=*s.begin();
        int end=*s.rbegin();
        int ans=beg+d;
        while(s.upper_bound(ans)!=s.end())
        {
            mp[beg]=j;
            int x=*s.upper_bound(ans);
            // cout<<"x="<<x<<endl;
            s.erase(beg);
            beg=x;
            ans=beg+d;
        }
        mp[beg]=j;
        s.erase(beg);
        j++;
    }
    cout<<j-1<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<mp[a[i].first]<<" ";
    }
}
signed main()
{
    sol();
    return 0;
}