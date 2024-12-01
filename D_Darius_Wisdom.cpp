#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n],arr[3]={};
    for(int i=0;i<n;++i)
    cin>>a[i];
    set<int>st[3];
    for(int i=0;i<n;++i)
    {
        arr[a[i]]++;
        st[a[i]].insert(i);
    }
    vector<pair<int,int>>vp;
    while((st[2].size() && *st[2].begin()<arr[0]+arr[1])||*st[1].begin()<arr[0])
    {
        if(st[2].size() && *st[1].rbegin()>=arr[1]+arr[0])
        {
            int i=*st[1].rbegin(),j=*st[2].begin();
            vp.push_back({i+1,j+1});
            st[1].erase(i);
            st[2].erase(j);
            st[1].insert(j);
            st[2].insert(i);
        }
        if(st[0].size() && *st[0].rbegin()>=arr[0])
        {
            int i=*st[0].rbegin(),j=*st[1].begin();
            vp.push_back({i+1,j+1});
            st[0].erase(i);
            st[1].erase(j);
            st[0].insert(j);
            st[1].insert(i);
        }
    }
    cout<<vp.size()<<endl;
    for(auto& it:vp)
    cout<<it.first<<" "<<it.second<<endl;
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