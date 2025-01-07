#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,q,a[N];
struct st
{
    int a[N];
    array<int,3>mask[N<<2];
    array<int,3>Merge(array<int,3>a,array<int,3>b)
    {
        array<int,3>Ans;
        Ans[1]=min(a[1],b[1]);
        Ans[2]=max(a[2],b[2]);
        Ans[0]=max({a[0],b[0],b[2]-a[1]});
        return Ans;
    }
    void Build(int l=0,int r=n,int id=1)
    {
        if(r-l==1)
        {
            mask[id]={0,a[l],a[l]};
            return;
        }
        int m=(l+r)/2;
        Build(l,m,2*id),Build(m,r,2*id+1);
        mask[id]=Merge(mask[2*id],mask[2*id+1]);
    }
    void Update(int i,int l=0,int r=n,int id=1)
    {
        if(r-l==1)
        {
            mask[id]={0,a[l],a[l]};
            return;
        }
        int m=(l+r)/2;
        if(i<m)Update(i,l,m,2*id);
        else Update(i,m,r,2*id+1);
        mask[id]=Merge(mask[2*id],mask[2*id+1]);
    }
    int Result()
    {
        return mask[1][0];
    }
};
pair<st,st>sg;
void sol()
{
    cin>>n>>q;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)
    {
        sg.first.a[i]=a[i]-i,sg.second.a[n-1-i]=a[i]-(n-1-i);
    }
    sg.first.Build(0,n),sg.second.Build(0,n);
    cout<<max(sg.first.Result(),sg.second.Result())<<endl;
    while(q--)
    {
        int p,x;
        cin>>p>>x;
        p--;
        sg.first.a[p]=x-p;
        sg.second.a[n-p-1]=x-(n-p-1);
        sg.first.Update(p,0,n),sg.second.Update(n-p-1,0,n);
        cout<<max(sg.first.Result(),sg.second.Result())<<endl;
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