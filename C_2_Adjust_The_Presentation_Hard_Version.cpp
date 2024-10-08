#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<int>a(n),b(m),presentation(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        a[i]--,presentation[a[i]]=i;
    }
    vector<set<int>>pos(n,{m});
    for(int i=0;i<m;++i)
    {
        cin>>b[i];
        b[i]--,b[i]=presentation[b[i]];
        pos[b[i]].insert(i);
    }
    int ans=0;
    auto representation=[&](int i)->int
    {
        if(i==0||i==n)return 0;
        set<int>::iterator it1=pos[i].begin();
        set<int>::iterator it2=pos[i-1].begin();
        return (*it1<*it2)?1:0;
    };
    for(int i=0;i<n;++i)ans+=representation(i);
    cout<<(ans?"TIDAK":"YA")<<endl;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        y=presentation[y];
        if(y!=b[x])
        {
            vector<int>Adjust={b[x],b[x]+1,y,y+1};
            sort(Adjust.begin(),Adjust.end());
            Adjust.resize(unique(Adjust.begin(),Adjust.end())-Adjust.begin());
            for(vector<int>::iterator it=Adjust.begin();it!=Adjust.end();++it)
            {
                ans-=representation(*it);
            }
            pos[b[x]].erase(x);
            b[x]=y;
            pos[y].insert(x);
            for(vector<int>::iterator it=Adjust.begin();it!=Adjust.end();++it)
            {
                ans+=representation(*it);
            }
        }
        cout<<(ans?"TIDAK":"YA")<<endl;
    }
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