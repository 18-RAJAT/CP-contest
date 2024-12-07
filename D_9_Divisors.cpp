#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4000000000005;

//Rajat Joshi Template
vector<int>recur(int l)
{
    vector<bool>p(l+1,1);
    p[0]=p[1]=0;
    for(int i=2;i*i<=l;++i)
    {
        if(p[i])
        {
            for(int j=i*i;j<=l;j+=i)p[j]=0;
        }
    }
    vector<int>res;
    for(int i=2;i<=l;++i)if(p[i])res.push_back(i);
    return res;
}
bool check(int p,int pw)
{
    int r=1;
    for(int i=0;i<pw;++i)
    {
        if(r>N/p)return 1;
        r*=p;
    }
    return 0;
}
void sol()
{
    int n;cin>>n;
    int l=sqrt(n);
    vector<int>res=recur(l);
    set<int>s;
    for(auto& p:res)
    {
        if(check(p,8))break;
        int prod=p*p,prod4=prod*prod,prod8=prod4*prod4;
        //combinations=n/prod8,n/prod4,n/prod
        if(prod8>n)break;
        s.insert(prod8);
    }
    int sz=res.size();
    for(int i=0;i<sz;++i)
    {
        int p1=res[i];
        if(check(p1,2))break;
        int root=p1*p1;
        if(root>n)break;
        for(int j=i+1;j<sz;++j)
        {
            int prod=res[j];
            if(check(prod,2))break;
            int prod1=prod*prod;
            // cout<<"prod1 "<<prod1<<endl;
            if(root>n/prod1)break;
            // assert(prod1<=n);
            int tot=root*prod1;
            if(tot<=n)s.insert(tot);
        }
    }
    // assert(s.size()<=n);
    cout<<s.size()<<endl;
}
signed main()
{
    sol();
    return 0;
}