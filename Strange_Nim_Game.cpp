#include<bits/stdc++.h>
using namespace std;
#define int long long

//Rajat joshi template FT
const int Mod=1000000007,NN=200000,NN_=200000;
int pow2Arr[NN_+1],grundy[NN+1],arrG[NN_+1],SegT[4*NN_][18];
void buildGrundy()
{
    grundy[0]=0;
    for(int x=1;x<=NN;++x)
    {
        int tmp=x;
        vector<int>nxt;
        while(tmp>0)
        {
            int d=tmp%10;
            if(d>=1)nxt.push_back(grundy[x-d]);
            tmp/=10;
        }
        static bool used[64];
        memset(used,false,sizeof(used));
        for(auto& it:nxt)if(it<64)used[it]=true;
        int m=0;
        while(m<64 && used[m])m++;
        grundy[x]=m;
    }
}
void Add(int* Nim,int x)
{
    for(int i=17;~i;--i)
    {
        if(((x>>i)&1)==0)continue;
        if(Nim[i]==0)
        {
            Nim[i]=x;
            return;
        }
        else
        {
            x^=Nim[i];
            if(x==0) return;
        }
    }
}
void Merge(int* out,int* b1,int* b2)
{
    memcpy(out,b1,sizeof(int)*18);
    for(int i=0;i<18;++i)if(b2[i]!=0)Add(out,b2[i]);
}

//Rajat joshi template Segtree
void buildTree(int node,int start,int end)
{
    if(start==end)
    {
        for(int i=0;i<18;++i)SegT[node][i]=0;
        if(arrG[start]!=0)Add(SegT[node],arrG[start]);
    }
    else
    {
        int mid=(start+end)>>1;
        buildTree(node*2,start,mid);
        buildTree(node*2+1,mid+1,end);
        Merge(SegT[node],SegT[node*2],SegT[node*2+1]);
    }
}
void updateTree(int node,int start,int end,int idx,int ng)
{
    if(start==end)
    {
        for(int i=0;i<18;++i) SegT[node][i]=0;
        if(ng!=0) Add(SegT[node],ng);
    }
    else
    {
        int mid=(start+end)>>1;
        if(idx<=mid)updateTree(node*2,start,mid,idx,ng);
        else updateTree(node*2+1,mid+1,end,idx,ng);
        Merge(SegT[node],SegT[node*2],SegT[node*2+1]);
    }
}
void queryTree(int node,int start,int end,int L,int R,int* out)
{
    if(R<start || end<L) return;
    if(L<=start && end<=R)
    {
        Merge(out,SegT[node],out);
        return;
    }
    int mid=(start+end)>>1;
    queryTree(node*2,start,mid,L,R,out);
    queryTree(node*2+1,mid+1,end,L,R,out);
}
int Dimension(int* Nim)
{
    int dim=0;
    for(int i=0;i<18;++i)if(Nim[i]!=0)dim++;
    return dim;
}
void sol()
{
    buildGrundy();
    pow2Arr[0]=1;
    for(int i=1;i<=NN_;++i)pow2Arr[i]=(pow2Arr[i-1]*2)%Mod;
    int N;
    cin>>N;
    for(int i=1;i<=N;++i)
    {
        int A;
        cin>>A;
        arrG[i]=grundy[A];
    }
    buildTree(1,1,N);
    int Q;
    cin>>Q;
    while(Q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int L,R;cin>>L>>R;
            int qB[18]={};
            queryTree(1,1,N,L,R,qB);
            int dim=Dimension(qB),len=R-L+1;
            int ans=(pow2Arr[len]-pow2Arr[len-dim]+Mod)%Mod;
            cout<<ans<<endl;
        }
        else
        {
            int i,x;cin>>i>>x;
            int ng=grundy[x];
            arrG[i]=ng;
            updateTree(1,1,N,i,ng);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sol();
    return 0;
}