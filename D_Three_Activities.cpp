#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n),c(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>c[i];
    }
    set<pair<int,int>>s1,s2;
    s1.insert(make_pair(a[0],0));
    s2.insert(make_pair(b[0],0));
    int ans=0;
    for(int i=0;i<n;++i)
    {
        s1.insert(make_pair(a[i],i));
    }
    for(int i=0;i<n;++i)
    {
        s2.insert(make_pair(b[i],i));
    }
    for(int i=0;i<n;++i)
    {
        int temp=c[i];
        s1.erase(make_pair(a[i],i));
        s2.erase(make_pair(b[i],i));
        auto q=*s1.rbegin();
        // set<pair<int,int>>::iterator q=s1.end();
        s2.erase(make_pair(b[q.second],q.second));
        auto q2=*s2.rbegin();
        ans=max(ans,temp+q.first+q2.first);
        s2.insert(make_pair(b[q.second],q.second));
        q=*s2.rbegin();
        s1.erase(make_pair(a[q.second],q.second));
        q2=*s1.rbegin();
        ans=max(ans,temp+q.first+q2.first);
        s1.insert(make_pair(a[q.second],q.second));
        s1.insert(make_pair(a[i],i));
        s2.insert(make_pair(b[i],i));
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