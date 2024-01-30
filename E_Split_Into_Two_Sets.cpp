#include<bits/stdc++.h>
using namespace std;
#define int long long
struct segTree
{
    vector<int>tree;
    int n;
    void init(int N)
    {
        n=N;
        tree.assign(4*n,0);
    }
    void update(int i,int l,int r,int pos,int val)
    {
        if(l>pos || r<pos)
        {
            return;
        }
        if(l==pos && r==pos)
        {
            tree[i]=val;
            return;
        }
        int mid=l+r>>1;
        update(2*i,l,mid,pos,val);
        update(2*i+1,mid+1,r,pos,val);
        tree[i]=tree[2*i]+tree[2*i+1];
    }
    int query(int i,int l,int r,int pos)
    {
        if(l>pos || r<pos)
        {
            return 0;
        }
        if(l>=pos && r<=pos)
        {
            return tree[i];
        }
        int mid=l+r>>1;
        return query(2*i,l,mid,pos)+query(2*i+1,mid+1,r,pos);
    }
    int query(int l)
    {
        return query(1,0,n-1,l);
    }
    void update(int pos,int val)
    {
        update(1,0,n-1,pos,val);
    }
};
void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first>>a[i].second;
    }
    segTree seg1,seg2;
    seg1.init(n+5);
    seg2.init(n+5);
    for(auto& it:a)
    {
        if(it.first==it.second)
        {
            cout<<"NO"<<endl;
            return;
        }
        if(seg1.query(it.first) || seg1.query(it.second))
        {
            if(seg2.query(it.first) || seg2.query(it.second))
            {
                cout<<"NO"<<endl;
                return;
            }
            else
            {
                seg2.update(it.first,1);
                seg2.update(it.second,1);
            }
        }
        else
        {
            seg1.update(it.first,1);
            seg1.update(it.second,1);
        }
    }
    cout<<"YES"<<endl;
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