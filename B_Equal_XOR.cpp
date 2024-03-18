#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int pos=2*n;
    vector<int> a(pos),p,q;
    for(int i=0;i<pos;++i)
    {
        cin>>a[i];
    }
    set<int> s1,s2;
    vector<int> v1,v2;
    for(int i=0;i<n;++i)
    {
        auto it=s1.find(a[i]);
        if(it==s1.end())
        {
            s1.insert(a[i]);
        }
        else
        {
            s1.erase(it);
            v1.push_back(a[i]);
        }
    }
    for(int i=n;i<pos;++i)
    {
        auto it=s2.find(a[i]);
        if(it==s2.end())
        {
            s2.insert(a[i]);
        }
        else
        {
            s2.erase(it);
            v2.push_back(a[i]);
        }
    }
    while(p.size()<2*k)
    {
        if(v1.empty()||v2.empty())
        {
            break;
        }
        p.push_back(v1.back());
        p.push_back(v1.back());
        v1.pop_back();
        q.push_back(v2.back());
        q.push_back(v2.back());
        v2.pop_back();
    }
    while(p.size()<2*k)
    {
        p.push_back(*s1.begin());
        q.push_back(*s2.begin());
        s1.erase(s1.begin());
        s2.erase(s2.begin());
    }
    for(int i=0;i<2*k;++i)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<2*k;++i)
    {
        cout<<q[i]<<" ";
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