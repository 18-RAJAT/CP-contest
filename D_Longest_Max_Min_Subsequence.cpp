#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls (x<<1)
#define rs (x<<1|1)
const int N=5e5+5;
int a[N],last[N],n;
vector<int>v[N];
set<int>s;
int v1[N<<2],v2[N<<2],mn[N<<2],mx[N<<2],min_max_overall[N<<2];
int Recur(int x)
{
    (v1[mx[ls]]>=v1[mx[rs]])?mx[x]=mx[ls]:mx[x]=mx[rs];
    
    (v2[mn[ls]]<=v2[mn[rs]])?mn[x]=mn[ls]:mn[x]=mn[rs];
}
void Build_Segment(int x,int l,int r)
{
    if(l==r)
    {
        min_max_overall[x]=l;
        mx[x]=mn[x]=x;
        v1[x]=v2[x]=a[l];
        return;
    }
    int mid=l+r>>1;
    Build_Segment(ls,l,mid);
    Build_Segment(rs,mid+1,r);
    Recur(x);
}
void Modify_Segment(int x,int l,int r,int pos)
{
    if(l==r)
    {
        v1[x]=0,v2[x]=LLONG_MAX;
        return;
    }
    int mid=l+r>>1;
    if(pos<=mid)Modify_Segment(ls,l,mid,pos);
    if(pos>mid)Modify_Segment(rs,mid+1,r,pos);
    Recur(x);
}
int Maximum_Query_Segment(int x,int l,int r,int L,int R)
{
    if(L<=l && r<=R)return mx[x];
    int mid=l+r>>1;
    if(R<=mid)return Maximum_Query_Segment(ls,l,mid,L,R);

    if(L>mid)return Maximum_Query_Segment(rs,mid+1,r,L,R);

    int p1=Maximum_Query_Segment(ls,l,mid,L,R);
    int p2=Maximum_Query_Segment(rs,mid+1,r,L,R);
    return v1[p1]>=v1[p2]?p1:p2;
}
int Minimum_Query_Segment(int x,int l,int r,int L,int R)
{
    if(L<=l && r<=R)return mn[x];
    int mid=l+r>>1;
    if(R<=mid)return Minimum_Query_Segment(ls,l,mid,L,R);

    if(L>mid)return Minimum_Query_Segment(rs,mid+1,r,L,R);
    
    int p1=Minimum_Query_Segment(ls,l,mid,L,R);
    int p2=Minimum_Query_Segment(rs,mid+1,r,L,R);
    return v2[p1]<=v2[p2]?p1:p2;
}
void sol()
{
    cin>>n;
    int largest=0;
    s.clear();
    for(int i=1;i<=n;++i)
    {
        last[i]=-1;
        v[i].clear();
    }
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        last[a[i]]=i;
        v[a[i]].push_back(i);
    }
    Build_Segment(1,1,n);
    for(int i=1;i<=n;++i)
    {
        if(last[i]==-1)
        {
            continue;
        }
        largest++;s.insert(last[i]);
    }
    cout<<largest<<endl;
    int l=1,r=(*s.begin());
    for(int i=1;i<=largest;++i)
    {
        int x;
        x=(i&1)?Maximum_Query_Segment(1,1,n,l,r):Minimum_Query_Segment(1,1,n,l,r);
        x=min_max_overall[x];
        s.erase(s.lower_bound(last[a[x]]));
        l=x+1;
        if(i!=largest)
        {
            r=(*s.begin());
        }
        cout<<a[x]<<" ";
        for(auto& it:v[a[x]])
        {
            Modify_Segment(1,1,n,it);
        }
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