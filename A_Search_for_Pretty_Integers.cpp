#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;cin>>n>>m;
    set<long long>s1,s2;
    for(long long i=0;i<n;++i)
    {
        long long x;
        cin>>x;
        s1.insert(x);
    }#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;cin>>n>>m;
    set<long long>s1,s2;
    for(long long i=0;i<n;++i)
    {
        long long x;
        cin>>x;
        s1.insert(x);
    }
    for(long long i=0;i<m;++i)
    {
        long long x;
        cin>>x;
        s2.insert(x);
    }
    // cout<<s1.size()<<" "<<s2.size()<<"\n";
    for(long long i=1;i<=9;++i)
    {
        if(s1.find(i)!=s1.end() and s2.find(i)!=s2.end())
        {
            cout<<i<<"\n";
            return 0;
        }
    }
    // cout<<-1<<"\n";
    cout<<min<long long>(*s1.begin(),*s2.begin())<<max<long long>(*s1.begin(),*s2.begin());
    return 0;
}
    for(long long i=0;i<m;++i)
    {
        long long x;
        cin>>x;
        s2.insert(x);
    }
    // cout<<s1.size()<<" "<<s2.size()<<"\n";
    for(long long i=1;i<=9;++i)
    {
        if(s1.find(i)!=s1.end() and s2.find(i)!=s2.end())
        {
            cout<<i<<"\n";
            return 0;
        }
    }
    // cout<<-1<<"\n";
    cout<<min<long long>(*s1.begin(),*s2.begin())<<max<long long>(*s1.begin(),*s2.begin());
    return 0;
}