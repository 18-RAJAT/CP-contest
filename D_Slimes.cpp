#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e18;
class sparse_table
{
protected:
    int n;
    vector<vector<int>>v;
    virtual int operation(int a,int n)=0;//pure virtual function

    int log2(int x)
    {
        return 31-__builtin_clz(x);
    }

    void build_table(vector<int>& vec)
    {
        n=vec.size();
        int value=1+log2(n);//Determine the number of levels in the sparse table
        v.resize(value,vector<int>(n));
        //First Level
        for(int i=0;i<n;++i)
        {
            v[0][i]=vec[i];
        }
        for(int i=1;i<value+1;++i)
        {
            for(int j=0;j+(1<<i)<=n;++j)
            {
                // Fill in the sparse table entry v[i][j] by combining entries from the previous level(i-1)
                // v[i][j] represents the result of the operation over the range[j,j+2^i-1]

                // The range is divided into two halves->
                // 1. The first half starts at index j and spans 2^(i-1) elements->v[i-1][j]
                // 2. The second half starts at index j+2^(i-1) and spans the next 2^(i-1) elements->v[i-1][j+(1<<(i-1))]
                v[i][j]=operation(v[i-1][j],v[i-1][j+(1<<(i-1))]);
            }
        }
    }
public:
    virtual void build(vector<int>& arr)
    {
        build_table(arr);
    }
    virtual int query(int l,int r)=0;
};


class min_sparse_table:public sparse_table
{
protected:
    int operation(int a,int b)override
    {
        return min(a,b);
    }
public:
    void build(vector<int>& arr)override
    {
        sparse_table::build(arr);
    }
    int query(int l,int r)override
    {
        if(r<l)swap(l,r);
        int value=log2(r-l+1);
        return min(v[value][l],v[value][r-(1<<value)+1]); 
    }
};


class max_sparse_table:public sparse_table
{
protected:
    int operation(int a,int b)override
    {
        return max(a,b);
    }
public:
    void build(vector<int>& arr)override
    {
        sparse_table::build(arr);
    }
    int query(int l,int r)override
    {
        if(r<l)swap(l,r);
        int value=log2(r-l+1);
        return max(v[value][l],v[value][r-(1<<value)+1]); 
    }
};
vector<int>slimes(vector<int>&nums)
{
    int n=nums.size();
    vector<int>ans(n,INF);
    vector<int>arr=nums;
    for(int i=1;i<n;++i)
    {
        arr[i]+=arr[i-1];
    }
    min_sparse_table* minimum_table=new min_sparse_table();
    minimum_table->build(nums);
    max_sparse_table* maximum_table=new max_sparse_table();
    maximum_table->build(nums);

    for(int i=0;i<n;++i)
    {
        if(i)
        {
            int l=0,r=i+1;
            while(l<r)
            {
                int mid=l+(r-l)/2;
                if(!(mid==i-1 || minimum_table->query(mid,i-1)<maximum_table->query(mid,i-1)) || arr[i-1]-(mid?arr[mid-1]:0)<=nums[i] || mid<0)
                {
                    r=mid;
                }
                else
                {
                    ans[i]=i-1-mid+1,l=mid+1;
                }
            }
        }
    }
    delete minimum_table;
    delete maximum_table;
    return ans;
}

void sol()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<nums.size();++i)
    {
        cin>>nums[i];
    }
    auto ans=slimes(nums);
    reverse(nums.begin(),nums.end());
    auto res=slimes(nums);
    reverse(res.begin(),res.end());
    for(int i=0;i<n;++i)
    {
        ans[i]=min(ans[i],res[i]);
        if(ans[i]>=INF)
        {
            cout<<-1<<" ";
        }
        else
        {
            cout<<ans[i]<<" ";
        }
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