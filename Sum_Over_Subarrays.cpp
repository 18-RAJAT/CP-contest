#include<bits/stdc++.h>
using namespace std;
#define int long long
//Rajat joshi template
struct Fenwick
{
    int n;
    vector<int>freq,sum;
    Fenwick(int size)
    {
        n=size+2;
        freq.assign(n,0);
        sum.assign(n,0);
    }
    void Update(int idx,int del)
    {
        while(idx<n)
        {
            freq[idx]+=del;
            idx+=idx&-idx;
        }
    }
    void Sum(int idx,int del)
    {
        while(idx<n)
        {
            sum[idx]+=del;
            idx+=idx&-idx;
        }
    }
    pair<int,int>Query(int idx)
    {
        int f=0,s=0;
        while(idx>0)
        {
            f+=freq[idx];
            s+=sum[idx];
            idx-=idx&-idx;
        }
        return{f,s};
    }
};
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>d(n+1,0);
    for(int i=1;i<=n;++i)
    {
        d[i]=d[i-1]+(s[i-1]=='0'?1:-1);
    }
    vector<int>arr(d);
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    auto idx=[&](int x)
    {
        return lower_bound(arr.begin(),arr.end(),x)-arr.begin()+1;
    };
    Fenwick Fn(arr.size());
    int id=idx(d[0]);
    Fn.Update(id,1);
    Fn.Sum(id,d[0]);
    int sum=0,tot=1,tmp=d[0];
    for(int i=1;i<=n;++i)
    {
        int x=d[i],p=idx(x);
        auto q=Fn.Query(p);
        int cl=q.first,sl=q.second,cr=tot-cl,sr=tmp-sl;
        // sum+=cl*sl-cr*sr;
        sum+=x*cl-sl+sr-x*cr;
        // cout<<"x-> cl "<<cl<<" sr"<<sl<<" cr"<<sr<<" sr"<<sum+cl*sl-cr*sr<<endl;
        Fn.Update(p,1);
        Fn.Sum(p,x);
        tot++,tmp+=x;
    }
    // cout<<(n+1)*n/2<<" "<<(n+2)<<" "<<(n+1)<<endl;
    int len=n*(n+1)*(n+2)/6;
    int a=len+sum;
    cout<<(a+1)/2<<endl;
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