#include<bits/stdc++.h>
using namespace std;
#define int long long
struct segtree
{
    int size;
    vector<int>sums;
    void init(int n)
    {
        size=1;
        while(size<n)
        {
            size*=2;
        }
        sums.assign(2*size,0LL);
    }
    void build(vector<int>&a,int x,int lx,int rx)
    {
        if(rx-lx==1)
        {
            if(lx<a.size())
            {
                sums[x]=a[lx];
            }
            return;
        }
        int m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }
    void build(vector<int>&a)
    {
        build(a,0,0,size);
    }
    void set(int i,int v,int x,int lx,int rx)
    {
        if(rx-lx==1)
        {
            sums[x]=v;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m)
        {
            set(i,v,2*x+1,lx,m);
        }
        else
        {
            set(i,v,2*x+2,m,rx);
        }
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }
    void set(int i,int v)
    {
        set(i,v,0,0,size);
    }
    int sum(int l,int r,int x,int lx,int rx)
    {
        if(lx>=r || l>=rx)
        {
            return 0;
        }
        if(lx>=l && rx<=r)
        {
            return sums[x];
        }
        int m=(lx+rx)/2;
        int s1=sum(l,r,2*x+1,lx,m);
        int s2=sum(l,r,2*x+2,m,rx);
        return s1+s2;
    }
    int sum(int l,int r)
    {
        return sum(l,r,0,0,size);
    }
};
void sol()
{
    int n,q;
    cin>>n>>q;
    segtree st;
    st.init(n);
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    st.build(a);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<st.sum(l-1,r)<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}