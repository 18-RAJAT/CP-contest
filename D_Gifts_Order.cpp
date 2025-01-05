#include<bits/stdc++.h>
using namespace std;
#define int long long
//Rajat joshi template
struct MinSegmentTree
{
    int n;
    vector<int>tree;
    MinSegmentTree(int size)
    {
        n=1;
        while(n<size)n<<=1;
        tree.assign(2*n,LLONG_MAX);
    }
    void update(int idx,int val)
    {
        idx+=n;
        tree[idx]=val;
        idx>>=1;
        while(idx>=1)
        {
            tree[idx]=min(tree[2*idx],tree[2*idx+1]);
            idx>>=1;
        }
    }
    int query_min(int l,int r)const
    {
        int res=LLONG_MAX;
        int left=l+n,right=r+n;
        while(left<right)
        {
            if(left&1)res=min(res,tree[left++]);
            if(right&1)res=min(res,tree[--right]);
            left>>=1;
            right>>=1;
        }
        return res;
    }
};
struct MaxSegmentTree
{
    int n;
    vector<int>tree;
    MaxSegmentTree(int size)
    {
        n=1;
        while(n<size)n<<=1;
        tree.assign(2*n,LLONG_MIN);
    }
    void update(int idx,int val)
    {
        idx+=n;
        tree[idx]=val;
        idx>>=1;
        while(idx>=1)
        {
            tree[idx]=max(tree[2*idx],tree[2*idx+1]);
            idx>>=1;
        }
    }
    int query_max(int l,int r)const
    {
        int res=LLONG_MIN;
        int left=l+n,right=r+n;
        while(left<right)
        {
            if(left&1)res=max(res,tree[left++]);
            if(right&1)res=max(res,tree[--right]);
            left>>=1;
            right>>=1;
        }
        return res;
    }
};
int CalculateMax(int n,MinSegmentTree &mnTree,MaxSegmentTree &mxTree,const vector<int> &c1,const vector<int> &c2)
{
    int MxDiff1=LLONG_MIN,MxDiff2=LLONG_MIN;
    for(int j=1;j<n;++j)
    {
        int curr=c1[j];
        int mni=mnTree.query_min(0,j);
        int diff1=curr-mni;
        MxDiff1=max(MxDiff1,diff1);
    }
    for(int j=1;j<n;++j)
    {
        int curr=c2[j];
        int mxi=mxTree.query_max(0,j);
        int diff2=mxi-curr;
        MxDiff2=max(MxDiff2,diff2);
    }
    return max({0LL,MxDiff1,MxDiff2});
}
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<int>c1(n,0),c2(n,0);
    for(int i=0;i<n;++i)
    {
        c1[i]=a[i]-(i+1);
        c2[i]=a[i]+(i+1);
    }
    MinSegmentTree mnTree(n);
    MaxSegmentTree mxTree(n);
    for(int i=0;i<n;++i)
    {
        mnTree.update(i,c1[i]);
        mxTree.update(i,c2[i]);
    }
    int maxi=CalculateMax(n,mnTree,mxTree,c1,c2);
    cout<<maxi<<endl;
    while(q--)
    {
        int p;
        int x;
        cin>>p>>x;
        p--;
        a[p]=x;
        c1[p]=a[p]-(p+1);
        c2[p]=a[p]+(p+1);
        mnTree.update(p,c1[p]);
        mxTree.update(p,c2[p]);
        int ans=CalculateMax(n,mnTree,mxTree,c1,c2);
        cout<<ans<<endl;
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