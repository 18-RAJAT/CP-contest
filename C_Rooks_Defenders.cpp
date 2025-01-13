#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    set<int>ar,br;
    vector<int>a(n,0),b(n,0);
    for(int i=0;i<=n;++i)
    {
        ar.insert(i);
        br.insert(i);
    }
    int x,y,x1,y1,t;
    while(q--)
    {
        cin>>t;
        if(t==1)
        {
            cin>>x>>y;
            x--,y--;
            if(a[x]==0)ar.erase(x);
            if(b[y]==0)br.erase(y);
            a[x]++,b[y]++;
        }
        if(t==2)
        {
            cin>>x>>y;
            x--,y--,a[x]--,b[y]--;
            if(a[x]==0)ar.insert(x);
            if(b[y]==0)br.insert(y);
        }
        if(t==3)
        {
            cin>>x>>y>>x1>>y1;
            x--,y--;
            if(*ar.lower_bound(x)>=x1 || *br.lower_bound(y)>=y1)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}
signed main()
{
    sol();
    return 0;
}