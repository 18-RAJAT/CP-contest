#include<bits/stdc++.h>
using namespace std;
#define int long long

//Rajat joshi template(Dynamic Segment)
struct Seg
{
    int k,n;
    set<int>st;
    vector<vector<int>>pos;
    multiset<int>ms;
    Seg(int k,int n,const vector<int>& a)
    {
        this->k=k;
        this->n=n;
        st.insert(-1);
        st.insert(n);
        pos=vector<vector<int>>(k);
        for(int i=0;i<n;++i)
        {
            if(a[i]<k)pos[a[i]].push_back(i);
            else st.insert(i);
        }
        for(int i=0;i<k;++i)sort(pos[i].begin(),pos[i].end());
        auto it=st.begin();
        int prev=*it;
        it++;
        while(it!=st.end())
        {
            int res=*it;
            int L=prev+1,R=res-1;
            if(L>R)
            {
                prev=res;
                it++;
                continue;
            }
            int ok=1;
            for(int x=0;x<k;++x)
            {
                auto LB=lower_bound(pos[x].begin(),pos[x].end(),L);
                if(LB==pos[x].end() || *LB>R)
                {
                    ok=0;
                    break;
                }
            }
            if(ok)ms.insert(R-L+1);
            prev=res;
            it++;
        }
    }
    int All(int L,int R)
    {
        for(int x=0;x<k;++x)
        {
            auto LB=lower_bound(pos[x].begin(),pos[x].end(),L);
            if(LB==pos[x].end() || *LB>R)return 0;
        }
        return 1;
    }
    void Add(int i)
    {
        auto LB=st.lower_bound(i);
        int res=*LB;
        LB--;
        int prev=*LB;
        if(All(prev+1,res-1))
        {
            auto rem=ms.find(res-1-(prev+1)+1);
            if(rem!=ms.end())ms.erase(rem);
        }
        st.insert(i);
        if(prev+1<=i-1 || i!=0 || ~prev)if(All(prev+1,i-1))ms.insert(i-1-(prev+1)+1);
        if(i+1<=res-1)
        {
            if(All(i+1,res-1))ms.insert(res-1-(i+1)+1);
        }
    }
    void Remove(int i)
    {
        auto it=st.find(i);
        if(it==st.end())return;
        auto init=it;
        init--;
        int prev=*init;
        auto next=it;
        next++;
        int res=*next;
        if(prev+1<=i-1)
        {
            if(All(prev+1,i-1))
            {
                auto rem=ms.find(i-1-(prev+1)+1);
                if(rem!=ms.end())ms.erase(rem);
            }
        }
        if(i+1<=res-1)
        {
            if(All(i+1,res-1))
            {
                auto rem=ms.find(res-1-(i+1)+1);
                if(rem!=ms.end())ms.erase(rem);
            }
        }
        st.erase(it);
        if(prev+1<=res-1 && prev!=0)
        {
            if(All(prev+1,res-1))ms.insert(res-1-(prev+1)+1);
        }
    }
    void AddPos(int x,int pos)
    {
        auto& tmp=this->pos[x];
        auto LB=lower_bound(tmp.begin(),tmp.end(),pos);
        tmp.insert(LB,pos);
    }
    void RemovePos(int x,int pos)
    {
        auto& tmp=this->pos[x];
        auto LB=lower_bound(tmp.begin(),tmp.end(),pos);
        if(LB!=tmp.end() && *LB==pos)tmp.erase(LB);
    }
};
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    for(auto& it:a)cin>>it;
    vector<int>arr;
    int P=1;
    while(P<=n+1)
    {
        arr.push_back(P);
        P<<=1;
    }
    int brr=arr.size();
    vector<Seg*>Mex;
    for(auto& it:arr)Mex.push_back(new Seg(it,n,a));
    while(q--)
    {
        int i,x;
        cin>>i>>x;
        i--;
        int L=a[i],R=a[i]+x;
        a[i]=R;
        for(int id=0;id<brr;++id)
        {
            int k=arr[id];
            Seg* ret=Mex[id];
            int left=L<k,right=R<k;
            if(left && !right)
            {
                if(L>=0 && L<k)ret->RemovePos(L,i);ret->Add(i);
            }
            else if(!left && right)
            {
                if(R>=0 && R<k)ret->AddPos(R,i);ret->Remove(i);
            }
            else
            {
                if(left && right)
                {
                    if(L>=0 && L<k)ret->RemovePos(L,i);
                    if(R>=0 && R<k)ret->AddPos(R,i);
                }
            }
        }
        int Ans=0;
        for(int id=0;id<brr;++id)
        {
            Seg* ret=Mex[id];
            if(!ret->ms.empty())Ans=max<int>(Ans,*ret->ms.rbegin());
        }
        cout<<Ans<<endl;
    }
    for(auto& it:Mex)delete it;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}