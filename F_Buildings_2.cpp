#include<bits/stdc++.h>
using namespace std;
#define int long long

struct FT
{
    int sza;
    vector<int>tree;
    FT(int n)
    {
        sza=n;
        tree.assign(n+1,0);
    }
    void add(int idx,int val=1)
    {
        while(idx<=sza)
        {
            tree[idx]+=val;
            idx+=idx&(-idx);
        }
    }
    int sum(int idx)
    {
        int res=0;
        while(idx>=1)
        {
            res+=tree[idx];
            idx-=idx&(-idx);
        }
        return res;
    }
    int range(int l,int r)
    {
        return sum(r)-sum(l-1);
    }
};
struct Query
{
    int left,right,id;
};
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>h(n+1);
    for(int i=1;i<=n;++i)cin>>h[i];
    vector<int>prev(n+1,0);
    stack<int>st;
    for(int j=1;j<=n;++j)
    {
        while(!st.empty() && h[st.top()]<=h[j])st.pop();
        if(st.empty())prev[j]=0;
        else prev[j]=st.top();
        st.push(j);
    }
    vector<Query>Q(q);
    for(int i=0;i<q;++i)
    {
        cin>>Q[i].left>>Q[i].right;
        Q[i].id=i;
    }
    sort(Q.begin(),Q.end(),[&](Query &a,Query &b)->bool
    {
        return (a.left!=b.left)?a.left<b.left:a.right<b.right;
    });
    vector<int>build(n);
    for(int j=1;j<=n;++j)build[j-1]=j;
    sort(build.begin(),build.end(),[&](const int &a,const int &b)->bool
    {
        return (prev[a]!=prev[b])?prev[a]<prev[b]:a<b;
    });
    vector<int>ans(q);
    FT BIT(n);
    int p=0;
    for(auto &q:Q)
    {
        int L=q.left,R=q.right;
        while(p<n && prev[build[p]]<=L)
        {
            BIT.add(build[p]);
            p++;
        }
        if(n<=R)ans[q.id]=0;
        else ans[q.id]=BIT.range(R+1,n);
    }
    for(int i=0;i<q;++i)cout<<ans[i]<<endl;
}
signed main()
{
    sol();
    return 0;
}