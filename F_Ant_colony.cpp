#include<bits/stdc++.h>
using namespace std;
#define int long long
struct SegTree
{
    int n;
    vector<int>arr,seg;
    int left(int x){return x<<1;}
    int right(int x){return (x<<1)|1;}
    int combine(int a,int b){return __gcd(a,b);}
    void build(int node,int start,int end)
    {
        if(start==end)
        {
            seg[node]=arr[start];
        }
        else
        {
            int mid=start+(end-start)/2;
            build(left(node),start,mid);
            build(right(node),mid+1,end);
            seg[node]=combine(seg[left(node)],seg[right(node)]);
        }
    }
    int query(int node,int start,int end,int i,int j)
    {
        if(i>j) return 0;
        if(i<=start && end<=j) return seg[node];
        int mid=start+(end-start)/2;
        return combine(query(left(node),start,mid,i,min(mid,j)),query(right(node),mid+1,end,max(i,mid+1),j));
    }
    SegTree(int n,vector<int>&a)
    {
        this->n=n;
        arr=a;
        seg=vector<int>(4*n,0);
        build(1,0,n-1);
    }
};
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<pair<int,int>>b(n);
    for(int i=0;i<n;++i)b[i]={a[i],i};
    sort(b.begin(),b.end());
    SegTree st(n,a);
    int Q;
    cin>>Q;
    while(Q--)
    {
        int l,r;
        cin>>l>>r;
        int x=st.query(1,0,n-1,l-1,r-1);
        pair<int,int>p={x,l-1};
        int start=lower_bound(b.begin(),b.end(),p)-b.begin();
        p={x,r};
        int end=lower_bound(b.begin(),b.end(),p)-b.begin();
        cout<<(r-l+1)-(end-start)<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}