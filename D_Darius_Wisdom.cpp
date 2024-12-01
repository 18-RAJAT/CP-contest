#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=3e5+5;
int a[N];
void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>>res;
    set<int>st[5];
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        st[a[i]].insert(i);
    }
    function<void(int,int)>recur=[&](int x,int y)->void
    {
        if(abs(a[x]-a[y])!=1)assert(0);if(a[x]<a[y])swap<int>(x,y);a[x]--,a[y]++;
    };
    int ans=(!st[2].empty()?2:1);
    vector<int>Arr(5);
    for(int i=n;i>=1;--i)
    {
        if(a[i]!=ans)
        {
            int Tmp=*st[a[i]+1].begin();
            res.push_back({i,Tmp});
            st[a[i]+1].erase(Tmp);
            st[a[i]].erase(i);
            st[a[i]+1].insert(i);
            st[a[i]].insert(Tmp);
            recur(i,Tmp);
        }
        if(a[i]!=ans)
        {
            int Tmp=*st[a[i]+1].begin();
            res.push_back({i,Tmp});
            st[a[i]+1].erase(Tmp);
            st[a[i]].erase(i);
            st[a[i]+1].insert(i);
            st[a[i]].insert(Tmp);
            recur(i,Tmp);
        }
        Arr[ans]++;
        if(st[ans].size()==Arr[ans])ans--;
    }
    cout<<res.size()<<endl;
    for(auto it:res)cout<<it.first<<" "<<it.second<<endl;
}
signed main()
{
    sol();
    return 0;
}