#include<bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,int>ind;
vector<int> seq1,seq2;
int Segment[4*1000010],n,a[1000010];
vector<int>cmp;
void update(int x,int y,int index=1,int start=0,int end=n)
{
    if(x<start || end<=x) return;
    if(end-start==1)
    {
        Segment[index]+=y;
        return;
    }
    int mid=(start+end)>>1;
    int left=2*index,right=2*index+1;
    update(x,y,left,start,mid);
    update(x,y,right,mid,end);
    Segment[index]=Segment[left]+Segment[right];
}
int query(int l,int r,int index=1,int start=0,int end=n)
{
    if(end<=l || r<=start)return 0;
    if(l<=start && end<=r)return Segment[index];
    int mid=(start+end)>>1;
    int left=2*index,right=2*index+1;
    return query(l,r,left,start,mid)+query(l,r,right,mid,end);
}
void compress_values()
{
    cmp=seq1;
    cmp.insert(cmp.end(),seq2.begin(),seq2.end());
    sort(cmp.begin(),cmp.end());
    cmp.erase(unique(cmp.begin(),cmp.end()),cmp.end());
}
int get_compressed_index(int x)
{
    return lower_bound(cmp.begin(),cmp.end(),x)-cmp.begin();
}
void sol()
{
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)
    {
        seq1.push_back(++ind[a[i]]);
    }
    for(int i=0;i<n;++i)
    {
        seq2.push_back(ind[a[i]]--);
    }
    compress_values();
    int maxi=cmp.size();
    fill(Segment,Segment+4*maxi,0);
    for(int i=0;i<n;++i)
    {
        int idx=get_compressed_index(seq2[i]);
        update(idx,1,1,0,maxi);
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        int idx2=get_compressed_index(seq2[i]);
        update(idx2,-1,1,0,maxi);
        int idx1=get_compressed_index(seq1[i]);
        ans+=query(0,idx1,1,0,maxi);
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}