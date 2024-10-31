#include<bits/stdc++.h>
using namespace std;
#define int long long
struct QueryTake
{
    int ok,right,min_value,max_value;
    bool operator<(const QueryTake&other)const{return ok<other.ok;}
};
class SegmentTree
{
    vector<int>TreeMn,TreeMx;
    int size;
    void build(const vector<int>&perm,int node,int start,int end)
    {
        if(start==end)
        {
            TreeMn[node]=perm[start];
            TreeMx[node]=perm[start];
        }
        else
        {
            int mid=start+(end-start)/2;
            build(perm,2*node,start,mid);
            build(perm,2*node+1,mid+1,end);
            TreeMn[node]=min(TreeMn[2*node],TreeMn[2*node+1]);
            TreeMx[node]=max(TreeMx[2*node],TreeMx[2*node+1]);
        }
    }
    int query_min(int node,int start,int end,int l,int r)
    {
        if(r<start || end<l)
        {
            return INT_MAX;
        }
        if(l<=start && end<=r)
        {
            return TreeMn[node];
        }
        int mid=start+(end-start)/2;
        return min(query_min(2*node,start,mid,l,r),query_min(2*node+1,mid+1,end,l,r));
    }
    int query_max(int node,int start,int end,int l,int r)
    {
        if(r<start || end<l)
        {
            return INT_MIN;
        }
        if(l<=start && end<=r)
        {
            return TreeMx[node];
        }
        int mid=start+(end-start)/2;
        return max(query_max(2*node,start,mid,l,r),query_max(2*node+1,mid+1,end,l,r));
    }
public:
    SegmentTree(const vector<int>&perm):size(perm.size()-1)
    {
        TreeMn.resize(4*size);
        TreeMx.resize(4*size);
        build(perm,1,1,size);
    }
    int query_min(int l,int r){return query_min(1,1,size,l,r);}
    int query_max(int l,int r){return query_max(1,1,size,l,r);}
};
void UpdateQuery(int a,int b,bool ok,set<QueryTake>&intervals,SegmentTree&Seg,int&flag,int n)
{
    if(a<1 || b>n || a>=b){return;}
    if(ok)
    {
        auto Bound_high=intervals.end(),it2=intervals.end();
        auto ending=intervals.lower_bound(QueryTake{a,0,0,0});
        (ending!=intervals.end() && ending->ok==a)?Bound_high=ending:Bound_high=(ending==intervals.begin())?ending:prev(ending);
        if(!(Bound_high->ok<=a && a<=Bound_high->right))
        {
            Bound_high=intervals.end();
            // ending=intervals.end();
        }
        auto LB=intervals.lower_bound(QueryTake{b,0,0,0});
        (LB!=intervals.end() && LB->ok==b)?it2=LB:it2=(LB==intervals.begin())?LB:prev(LB);
        // for(auto it=intervals.begin();it!=intervals.end();it++)
        // {
        //     cout<<it->ok<<" "<<it->right<<" "<<it->min_value<<" "<<it->max_value<<endl;
        // }
        if(!(it2->ok<=b && b<=it2->right))
        {
            it2=intervals.end();
        }
        if(Bound_high!=intervals.end() && it2!=intervals.end() && Bound_high!=it2)
        {
            if(Bound_high->min_value!=Bound_high->ok || Bound_high->max_value!=Bound_high->right)flag--;
            if(it2->min_value!=it2->ok||it2->max_value!=it2->right)flag--;
            int range_init=min(Bound_high->ok,it2->ok),range_final=max(Bound_high->right,it2->right);
            // for(auto it=range_init;it<=range_final;it++)
            // {
            //     cout<<Seg.query_min(it,it)<<" "<<Seg.query_max(it,it)<<endl;
            // }
            int range_in=Seg.query_min(range_init,range_final),range_out=Seg.query_max(range_init,range_final);
            QueryTake new_interval={range_init,range_final,range_in,range_out};
            if(range_in!=range_init ||  range_out!=range_final)flag++;
            // for(auto it=intervals.begin();it!=intervals.end();)
            // {
            //     cout<<it->ok<<" "<<it->right<<" "<<it->min_value<<" "<<it->max_value<<endl;
            //     it++;
            // }
            intervals.erase(Bound_high);
            intervals.erase(it2);
            intervals.insert(new_interval);
            // cout<<flag<<endl;
        }
    }
    else
    {
        auto Bound_low=intervals.lower_bound(QueryTake{a,0,0,0});
        if(Bound_low==intervals.end() || Bound_low->ok>a)
        {
            if(Bound_low==intervals.begin())
            {
                return;
            }
            Bound_low=prev(Bound_low);
        }
        if(Bound_low->ok<=a && a<=Bound_low->right)
        {
            if(Bound_low->ok==Bound_low->right){return;}
            // auto& Bound_low_interval=*Bound_low;
            // int range_in=Seg.query_min(Bound_low_interval.ok,a),range_out=Seg.query_max(Bound_low_interval.ok,a);
            // QueryTake left_interval={Bound_low_interval.ok,a,range_in,range_out};
            // int range_in_2=Seg.query_min(a+1,Bound_low_interval.right),range_out_2=Seg.query_max(a+1,Bound_low_interval.right);
            QueryTake left_interval={Bound_low->ok,a,Seg.query_min(Bound_low->ok,a),Seg.query_max(Bound_low->ok,a)};
            QueryTake right_interval={a+1,Bound_low->right,Seg.query_min(a+1,Bound_low->right),Seg.query_max(a+1,Bound_low->right)};
            if(Bound_low->min_value!=Bound_low->ok||Bound_low->max_value!=Bound_low->right)flag--;
            if(left_interval.min_value!=left_interval.ok||left_interval.max_value!=left_interval.right)flag++;
            if(right_interval.min_value!=right_interval.ok||right_interval.max_value!=right_interval.right)flag++;

            // cout<<flag<<endl;
            // for(auto& i:intervals)
            // {
            //     cout<<i.ok<<" "<<i.right<<" "<<i.min_value<<" "<<i.max_value<<endl;
            // }
            intervals.erase(Bound_low);
            intervals.insert(left_interval);
            intervals.insert(right_interval);
            // cout<<flag<<endl;
        }
    }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<int>perm(n+1);
        for(int i=1;i<=n;++i)
        {
            cin>>perm[i];
        }
        SegmentTree Seg(perm);
        string s;
        cin>>s;
        set<QueryTake>intervals;
        int flag=0,ok=1;
        for(int i=2;i<=n;++i)
        {
            if(s[i-1]=='L' || s[i-2]=='R'){continue;}
            else
            {
                int right=i-1;
                int Min_vals=Seg.query_min(ok,right);
                int Max_vals=Seg.query_max(ok,right);
                if(Min_vals!=ok || Max_vals!=right)
                {
                    flag++;
                }
                QueryTake QueryTake={ok,right,Min_vals,Max_vals};
                intervals.insert(QueryTake);
                ok=i;
            }
            // for(auto& i:intervals)
            // {
            //     cout<<i.ok<<" "<<i.right<<" "<<i.min_value<<" "<<i.max_value<<endl;
            // }        
        }
        int right=n,Min_vals=Seg.query_min(ok,right),Max_vals=Seg.query_max(ok,right);
        if(Min_vals!=ok || Max_vals!=right)
        {
            flag++;
        }
        // else
        // {
        //     QueryTake QueryTake={ok,right,Min_vals,Max_vals};
        // }
        QueryTake QueryTake={ok,right,Min_vals,Max_vals};
        intervals.insert(QueryTake);
        while(q--)
        {
            int x;
            cin>>x;
            char temp=s[x-1];
            s[x-1]=(s[x-1]=='L')?'R':'L';
            int request_1=(temp=='L') || (x-1>=1 && s[x-2]=='R');
            int request_2=(s[x-1]=='L') || (x-1>=1 && s[x-2]=='R');
            if(request_1!=request_2)
            {
                (request_2)?UpdateQuery(x-1,x,true,intervals,Seg,flag,n):UpdateQuery(x-1,x,false,intervals,Seg,flag,n);
            }
            int request_l=(temp=='R') || (x+1<=n && s[x]=='L');
            int request_r=(s[x-1]=='R') || (x+1<=n && s[x]=='L');
            // for(auto& i:intervals)
            // {
            //     cout<<i.ok<<" "<<i.right<<" "<<i.min_value<<" "<<i.max_value<<endl;
            // }
            // cout<<flag<<endl;
            if(request_l!=request_r)
            {
                (request_r)?UpdateQuery(x,x+1,true,intervals,Seg,flag,n):UpdateQuery(x,x+1,false,intervals,Seg,flag,n);
            }
            cout<<(flag==0?"YES":"NO")<<endl;
        }
    }
}