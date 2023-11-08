#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int left,right,len,val;
};
struct SegmentTree
{
    int n;
    vector<int>a;
    vector<node>tree;
    void init(int x,vector<int>y)
    {
        n=x;
        a=y;
        tree.resize(4*n);
        build(1,0,n-1);
    }
    node merge(node x,node y)
    {
        if(x.val!=0)
        {
            return y;
        }
        if(y.val!=0)
        {
            return x;
        }
        // node ans;
        // ans.left=x.left;
        // ans.right=y.right;
        // ans.len=x.len+y.len;
        // ans.val=x.val+y.val;
        // return ans;
        if(x.right+1==y.left)
        {
            return {x.left,y.right,x.len+y.len,0};
        }
        else
        {
            if(x.len==y.len)
            {
                return x;
            }
            else
            {
                if(x.len>y.len)
                {
                    return x;
                }
                else
                {
                    return y;
                }
            }
        }
    }
    void build(int v,int tl,int tr)
    {
        if(tl==tr)
        {
            tree[v]={tl,tl,1};//for the case when n=1 and we have to return {0,0,1,0} instead of {0,0,1,1}
            return;
        }
        int mid=tl+(tr-tl)/2;
        build(2*v,tl,mid);//left child
        build(2*v+1,mid+1,tr);//right child
        tree[v]=merge(tree[2*v],tree[2*v+1]);//merging the left and right child
    }
    void modify(int i,int left,int right,int position)
    {
        if(left>position || right<position)
        {
            return;
        }
        if(left==right && left==position)
        {
            tree[i]=node{1,1,1,1};
            return;
        }
        if(left>=position && right<=position)
        {
            // tree[i]={left,right,1,1};
            tree[i]=node{-1,-1,-1,1};
            return;
        }
        int mid=left+(right-left)/2;
        modify(2*i,left,mid,position);//left child
        modify(2*i+1,mid+1,right,position);//right child
        tree[i]=merge(tree[2*i],tree[2*i+1]);///merging the left and right child to the parent
    }
    // node query(int i,int left,int right,int l,int r)
    // {
    //     if(left>r || right<l)
    //     {
    //         return {-1,-1,-1,0};
    //     }
    //     if(left>=l && right<=r)
    //     {
    //         return tree[i];
    //     }
    //     int mid=left+(right-left)/2;
    //     node x=query(2*i,left,mid,l,r);
    //     node y=query(2*i+1,mid+1,right,l,r);
    //     return merge(x,y);
    // }
    void modify(int position)
    {
        modify(1,0,n-1,position);
    }
};
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    int ans=1;
    SegmentTree segT;
    segT.init(n,vector<int>(n,0));
    for(int i=0;i<n;++i)
    {
        int l=segT.tree[1].left;
        int r=segT.tree[1].right;
        int len=segT.tree[1].len;
        if(len&1)
        {
            len=(len+1)/2;
        }
        else
        {
            len/=2;
        }
        int mid=l+len-1;
        a[mid]=ans++;
        segT.modify(mid);
    }
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
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