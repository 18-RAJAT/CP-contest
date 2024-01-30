#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>a;
class segTree
{
    public:
    int n;
    vector<int>tree;
    segTree(int n)
    {
        this->n=n;
        tree.resize(4*n);
    }
    void build(int node,int start,int end)
    {
        if(start==end)
        {
            tree[node]=a[start];
        }
        else
        {
            int mid=(start+end)/2;
            build(2*node,start,mid);
            build(2*node+1,mid+1,end);
            tree[node]=max(tree[2*node],tree[2*node+1]);
        }
    }
    void update(int node,int start,int end,int idx,int val)
    {
        if(start==end)
        {
            a[idx]=val;
            tree[node]=val;
        }
        else
        {
            int mid=(start+end)/2;
            if(start<=idx && idx<=mid)
            {
                update(2*node,start,mid,idx,val);
            }
            else
            {
                update(2*node+1,mid+1,end,idx,val);
            }
            tree[node]=max(tree[2*node],tree[2*node+1]);
        }
    }
    int query(int node,int start,int end,int l,int r)
    {
        if(r<start || end<l)
        {
            return 0;
        }
        if(l<=start && end<=r)
        {
            return tree[node];
        }
        int mid=(start+end)/2;
        int p1=query(2*node,start,mid,l,r);
        int p2=query(2*node+1,mid+1,end,l,r);
        return max(p1,p2);
    }
};
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    segTree st(n);
    st.build(1,0,n-1);
    vector<int>dp(n);
    for(int i=0;i<n;++i)
    {
        dp[i]=st.query(1,0,n-1,0,i-1);
    }
    vector<int>dp2(n);
    for(int i=n-1;i>=0;--i)
    {
        dp2[i]=st.query(1,0,n-1,i+1,n-1);
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ans=max(ans,a[i]+dp[i]+dp2[i]);
    }
    cout<<ans<<endl;
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