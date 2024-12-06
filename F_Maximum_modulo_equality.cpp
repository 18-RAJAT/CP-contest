#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>buildSparseTable(const vector<int>& diff,int n)
{
    int bit=0;
    while((1<<bit)<=n)++bit;
    vector<vector<int>>st(bit,vector<int>(n));
    for(int i=0;i<n;++i)st[0][i]=diff[i];
    for(int k=1;k<bit;++k)
    {
        for(int i=0;i+(1<<k)<=n;++i)
        {
            st[k][i]=__gcd(st[k-1][i],st[k-1][i+(1<<(k-1))]);
        }
    }
    return st;
}

int queryGCD(const vector<vector<int>>& st,const vector<int>& LogTable,int L,int R)
{
    if(L>=R)return 0;
    int length=R-L;
    int k=LogTable[length];
    return __gcd(st[k][L],st[k][R-(1<<k)]);
}
void sol()
{
    static const int MAX=200005;
    static vector<int>LogTable(MAX+1,0);
    static bool ok=false;
    if(!ok)
    {
        for(int i=2;i<=MAX;++i)LogTable[i]=LogTable[i/2]+1;
        ok=true;
    }
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<int>diff;
    if(n>=2)
    {
        diff.resize(n-1);
        for(int i=0;i<n-1;++i)diff[i]=abs(a[i+1]-a[i]);
    }
    vector<vector<int>>st;
    if(!diff.empty())st=buildSparseTable(diff,diff.size());
    
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        --l;--r;
        if(r-l<=0)cout<<"0 ";
        else
        {
            cout<<queryGCD(st,LogTable,l,r)<< " ";
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