#include<bits/stdc++.h>
using namespace std;
#define int long long

//rajat joshi template
struct Query//Bars table
{
    int R,C,L,Id;
};
struct SegmentTree
{
    int n;
    vector<int>tree,lazy;
    SegmentTree(int size)
    {
        n=1;
        while(n<size)n<<=1;
        tree.assign(2*n,0LL);
        lazy.assign(2*n,-1LL);
    }
    void build(int size,int init)
    {
        for(int i=0;i<size;++i)
        {
            tree[n+i]=init;
        }
        for(int i=n-1;i>=1;--i)
        {
            tree[i]=min(tree[2*i],tree[2*i+1]);
        }
    }
    void push(int node,int l,int r)
    {
        if(~lazy[node])
        {
            tree[node]=lazy[node];
            if(node<n)
            {
                lazy[2*node]=lazy[node];
                lazy[2*node+1]=lazy[node];
            }
            lazy[node]=-1;
        }
    }
    int MiniQ(int node,int l,int r,int Ql,int Qr)
    {
        push(node,l,r);
        if(r<Ql || l>Qr)return LLONG_MAX;
        if(Ql<=l && r<=Qr)return tree[node];
        int mid=(l+r)/2;
        return min(MiniQ(2*node,l,mid,Ql,Qr),MiniQ(2*node+1,mid+1,r,Ql,Qr));
    }
    void Range(int node,int l,int r,int Ql,int Qr,int val)
    {
        push(node,l,r);
        if(r<Ql || l>Qr)return;
        if(Ql<=l && r<=Qr)
        {
            lazy[node]=val;
            push(node,l,r);
            return;
        }
        int mid=(l+r)/2;
        Range(2*node,l,mid,Ql,Qr,val);
        Range(2*node+1,mid+1,r,Ql,Qr,val);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
    int MiniQ(int Ql,int Qr)
    {
        return MiniQ(1,1,n,Ql,Qr);
    }
    void Range(int Ql,int Qr,int val)
    {
        Range(1,1,n,Ql,Qr,val);
    }
};
signed main()
{
    int h,w,n;
    cin>>h>>w>>n;
    vector<Query>Arr(n);
    for(int i=0;i<n;++i)
    {
        cin>>Arr[i].R>>Arr[i].C>>Arr[i].L;
        Arr[i].Id=i;
    }
    sort(Arr.begin(),Arr.end(),[&](Query&a,Query&b)->bool
    {
        if(a.R!=b.R)return a.R>b.R;
        return a.Id>b.Id;
    });
    SegmentTree st(w);
    st.build(w,(int)h+1);
    vector<int>ans(n,0);
    for(auto& Query:Arr)
    {
        int x=Query.C,y=Query.C+Query.L-1;
        y=min(y,w);
        int F=st.MiniQ(x,y),Last=max((int)Query.R,F-1);
        ans[Query.Id]=Last;
        st.Range(x,y,Last);
    }
    for(int i=0;i<n;++i)cout<<ans[i]<<endl;
}