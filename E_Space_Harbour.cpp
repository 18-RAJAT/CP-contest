#include<bits/stdc++.h>
using namespace std;
#define int long long

struct segTree
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
        sums.assign(2*size-1,0);
    }
    void build(vector<int> &a,int x,int lx,int rx)
    {
        if(rx-lx==1)
        {
            if(lx<a.size())
            {
                sums[x]=a[lx];
            }
            else
            {
                sums[x]=0;
            }
            return;
        }
        int m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }
    void build(vector<int> &a)
    {
        build(a,0,0,size);
    }
    void multiset(int i,int v,int x,int lx,int rx)
    {
        if(rx-lx==1)
        {
            sums[x]=v;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m)
        {
            multiset(i,v,2*x+1,lx,m);
        }
        else
        {
            multiset(i,v,2*x+2,m,rx);
        }
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }
    void multiset(int i,int v)
    {
        multiset(i,v,0,0,size);
    }
    int sum(int l,int r,int x,int lx,int rx)
    {
        if(lx>=r || l>=rx)
        {
            return 0;
        }
        if(rx-lx==1)
        {
            return sums[x];
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
        if(r<=l)
        {
            return 0;
        }
        return sum(l,r,0,0,size);
    }
};
int left_most(multiset<int> &s,int l,vector<int> &val)
{
    auto it=s.lower_bound(l);
    if(*it==l)
    {
        return 0;
    }
    int difference=*it-l;
    it--;
    // for(auto it=s.begin();it!=s.end();++it)
    // {
    //     cout<<*it<<" ";
    // }
    int v=val[*it];
    return difference*(difference+1)/2*v;
}
int right_most(multiset<int> &s,int r,vector<int> &val)
{
    auto it=s.lower_bound(r);
    if(*it==r)
    {
        return 0;
    }
    // for(auto it=s.begin();it!=s.end();++it)
    // {
    //     cout<<*it<<" ";
    // }
    int beg=*it-r;
    it--;
    int v=val[*it];
    int n=r-*it;
    // for(int i=0;i<n;++i)
    // {
    //     cout<<beg+i<<" ";
    // }
    return n*(2*beg+n-1)/2*v;
}
int check(multiset<int> &s,int l,int r)
{
    auto it1=s.lower_bound(l);
    auto it2=s.lower_bound(r);
    if(*it1==*it2)
    {
        return 0;
    }
    return 1;
}
int left_most_vals(multiset<int> &s,int l,int r,vector<int> &val)
{
    auto it=s.lower_bound(r);
    int beg=*it-r;
    it--;
    int v=val[*it];
    int n=r-l+1;
    // for(auto it=s.begin();it!=s.end();++it)
    // {
    //     cout<<*it<<" ";
    // }
    return n*(2*beg+n-1)/2*v;
}
void sol()
{
    int n,m,q;
    cin>>n>>m>>q;
    segTree seg;
    seg.init(n);
    multiset<int>s;
    int current=0,previous=0;
    vector<int>val;
    val.assign(n,0);
    vector<int>sum;
    sum.assign(n,0);
    vector<int>recur1(m),recur2(m);
    for(int i=0;i<m;++i)
    {
        cin>>recur1[i];
    }
    for(int i=0;i<m;++i)
    {
        cin>>recur2[i];
    }
    for(int i=0;i<m;++i)
    {
        recur1[i]--;
        // recur2[i]--;
        int x=recur1[i],v=recur2[i];
        if(x==0)
        {
            sum[x]=0;
            val[x]=v;
            previous=x;
            current=v;
            s.insert(x);
            continue;
        }
        int difference=x-previous;
        sum[x]=difference*(difference-1)/2*current;
        // cout<<"sum["<<x<<"] = "<<sum[x]<<endl;
        // cout<<"difference = "<<difference<<endl;
        // cout<<"current = "<<current<<endl;
        val[x]=v;
        previous=x;
        current=v;
        s.insert(x);
    }
    seg.build(sum);
    while(q--)
    {
        int t;
        cin>>t;
        if(t<=1)
        {
            int x,v;
            cin>>x>>v;
            x--;
            auto it=s.lower_bound(x);
            int x2=*it;
            it--;
            int x1=*it;
            int v1=val[x1];
            val[x]=v;
            int direction1=x-x1;
            int direction2=x2-x;
            // cout<<direction1*(direction1+1)/2*v1+direction2*(direction2+1)/2*v<<endl;
            sum[x]=direction1*(direction1-1)/2*v1;
            sum[x2]=direction2*(direction2-1)/2*v;
            // int maximum=max(x1,x2);
            //for x1+1 to x-1 sum[i]=sum[i-1]+v1 and for x+1 to x2-1 sum[i]=sum[i-1]+v
            for(int i=x1+1;i<x;++i)
            {
                sum[i]=sum[i-1]+v1;
            }
            for(int i=x+1;i<x2;++i)
            {
                sum[i]=sum[i-1]+v;
            }
            // cout<<x1<<" "<<x2<<endl;
            seg.multiset(x2,sum[x2]);
            seg.multiset(x,sum[x]);
            s.insert(x);
            continue;
        }
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        auto it1=s.lower_bound(l);
        auto it2=s.lower_bound(r);
        // for(auto it=s.begin();it!=s.end();++it)
        // {
        //     cout<<*it<<" ";
        // }
        if(*it1==*it2)
        {
            cout<<left_most_vals(s,l,r,val)<<endl;
            continue;
        }
        if(check(s,l,r))
        {
            cout<<left_most(s,l,val)+right_most(s,r,val)<<endl;
            continue;
        }
        // int s1=*it1,s2=*it2;
        // int val1=val[s1],val2=val[s2];
        // int direction1=s1-l,direction2=r-s2;
        // int ans=direction1*(direction1+1)/2*val1+direction2*(direction2+1)/2*val2;
        // cout<<ans+seg.sum(s1+1,s2+1)<<endl;
        cout<<left_most(s,l,val)+right_most(s,r,val)+seg.sum(*it1+1,r+1)<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}