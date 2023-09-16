#include<bits/stdc++.h>
using namespace std;
#define int long long
int tree[4*100005][11];
void update(int pos,int val,int k,int start,int end,int node=1)
{
    if(pos<start||pos>end)
    {
        return;
    }
    if(start==end)
    {
        tree[node][k]=val;
        return;
    }
    int mid=(start+end)/2;
    update(pos,val,k,start,mid,2*node);
    update(pos,val,k,mid+1,end,2*node+1);
    tree[node][k]=tree[2*node][k]+tree[2*node+1][k];
}
int query(int left,int right,int k,int start,int end,int node=1)
{
    if(left>end||right<start)
    {
        return 0;
    }
    if(left<=start&&right>=end)
    {
        return tree[node][k];
    }
    int mid=(start+end)/2;
    return query(left,right,k,start,mid,2*node)+query(left,right,k,mid+1,end,2*node+1);
}
void sol()
{
    int n,k;
    cin>>n>>k;
    if(!k)
    {
        cout<<n<<endl;
        return;
    }
    else
    {
        for(int i=1;i<=n;++i)
        {
            update(i,0,1,1,n);
        }
        for(int i=1;i<=n;++i)
        {
            update(i,0,2,1,n);
        }
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        ans+=query(1,x-1,k,1,n);
        update(x,1,1,1,n);
        for(int j=2;j<=k;++j)
        {
            int temp=query(1,x-1,j-1,1,n);
            update(x,temp,j,1,n);
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}