#include<bits/stdc++.h>
using namespace std;
#define int long long
struct seg_tree_items
{
    int value;
};
class SegTree
{
    int n;
    seg_tree_items null;
    vector<seg_tree_items>tree;
 
    void seg_update(int ind,int l,int r,seg_tree_items value,int i)
    {
        if(l==r)
        {
            tree[ind]=value;
        }
        else
        {
            int mid=(l+r)/2;
            (i<=mid)?seg_update(2*ind,l,mid,value,i):seg_update(2*ind+1,mid+1,r,value,i);
            tree[ind]=merge(tree[2*ind],tree[2*ind+1]);
        }
    }
    seg_tree_items query(int ind,int l,int r,int L,int R)
    {
        int mid=(l+r)/2;
        if(L>R)return this->null;
        return (l==L && r==R)?tree[ind]:merge(query(2*ind,l,mid,L,min(mid,R)),query(2*ind+1,mid+1,r,max(mid+1,L),R));
    }
    seg_tree_items merge(seg_tree_items a,seg_tree_items b)
    {
        return {max(a.value,b.value)};
    }
 
public:
    SegTree(int n)
    {
        this->n=n;
        tree.resize(4*n);
        this->null={0};
    }
    seg_tree_items query(int l,int r)
    {
        return query(1,1,n,l,r);
    }
    void seg_update(seg_tree_items value,int i)
    {
        seg_update(1,1,n,value,i);
    }
};
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    set<pair<int,int>>ele;
    SegTree st(n);
    for(int i=0;i<n;++i)
    {
        st.seg_update({a[i]},i+1);
        ele.insert({i+1,a[i]});
    }
    vector<int>ind(n+1,0),ans(n,1);
    for(int i=0;i<n;++i)
    {
        ind[a[i]]=i+1;
    }
    int team=0;
    while(!ele.empty())
    {
        int l=(*ele.begin()).first,r=(*ele.rbegin()).first;
        int query_ele=st.query(l,r).value,i=ind[query_ele],q=k+1;
        auto it = ele.find({i,query_ele});
        vector<pair<int,int>>pairs;
        while(q--)
        {
            pairs.push_back(*it);
            if(it==ele.begin())
            {
                break;
            }
            it--;
        }
        q=k;
        it=ele.find({i,query_ele});
        while(q--)
        {
            it++;
            if(it==ele.end())
            {
                break;
            }
            pairs.push_back(*it);
        }
        for(auto &it:pairs)
        {
            ans[it.first-1]=team+1;
            st.seg_update({0},it.first);
            ele.erase(it);
        }
        team++;
        team%=2;
    }
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i];
    }
}
signed main()
{
    sol();
    return 0;
}