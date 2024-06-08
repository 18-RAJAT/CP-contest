#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int arr[n],a[n],b[n];
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    set<pair<int,int>>st[4];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        st[a[i]].insert({arr[i],i});
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
        st[b[i]].insert({arr[i],i});
    }
    int m;
    cin>>m;
    while(m--)
    {
        int c;
        cin>>c;
        if(st[c].empty())
        {
            cout<<-1<<" ";
        }
        else
        {
            int first=st[c].begin()->first;
            int second=st[c].begin()->second;
            cout<<first<<" ";
            st[a[second]].erase({arr[second],second});
            st[b[second]].erase({arr[second],second});
        }
    }
}
signed main()
{
    sol();
    return 0;
}