#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD=1000000007;

class CircularArray
{
private:
    vector<int>a;
    vector<int>query_prod;

public:
    CircularArray(int size):a(size*2),query_prod(size*2+1,0){}
    void initialize()
    {
        int n=a.size()/2;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            a[i+n]=a[i];
        }
        partial_sum(a.begin(),a.end(),query_prod.begin()+1);
    }
    int query(int l,int r)const
    {
        int n=a.size()/2;
        int fullCycles=r/n-l/n-1;
        int ans=query_prod[n]*fullCycles;
        ans+=query_prod[l/n +n]-query_prod[l/n+l%n];
        ans+=query_prod[r/n+r%n+1]-query_prod[r/n];
        return ans%MOD;
    }
};

void sol()
{
    int n,q;
    cin>>n>>q;
    CircularArray arr(n);
    arr.initialize();
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;
        cout<<arr.query(l,r)<<endl;
    }
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