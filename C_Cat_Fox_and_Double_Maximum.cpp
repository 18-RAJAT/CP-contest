#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>cat_fox(vector<int>a)
{
    int n=a.size();
    vector<bool>taken(n);
    set<pair<int,int>>st;
    bool ok=false;
    for(int i=1;i<n-1;i+=2)
    {
        if(a[i]==1)ok=true;
    }
    if(!ok)
    {
        for(int i=1;i<n-1;i+=2)
        {
            st.insert({-a[i],i});
        }    
    }
    else
    {
        for(int i=2;i<n-1;i+=2)
        {
            st.insert({-a[i],i});
        }
    }
    int fox_max=n/2+2;
    vector<int>res(n);
    while(!st.empty())
    {
        auto[v,i]=(*st.begin());
        st.erase(st.begin());v=-v;
        if(taken[i-1] || taken[i+1])continue;
        taken[i]=true,res[i]=fox_max,fox_max++;
    }
    fox_max=n/2+1;
    for(int i=0;i<n;++i)
    {
        if(!taken[i])
        {
            st.insert({a[i],i});
        }
    }
    while(!st.empty())
    {
        auto[v,i]=(*st.begin());
        st.erase(st.begin());
        res[i]=fox_max,fox_max--;
    }
    return res;
}
int recur(vector<int>a)
{
    int count=0;
    vector<int>b=cat_fox(a);
    int n=a.size();
    for(int i=0;i<n;++i)
    {
        b[i]+=a[i];
    }
    a=b;
    for(int i=1;i<n-1;++i)
    {
        if(a[i-1]<a[i] && a[i+1]<a[i])count++;
    }
    return count==n/2-1;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    auto res=cat_fox(a);
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
    return 0;
}