#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int Pow(int x,int p)
{
    int ans=1;
    x%=MOD;
    while(p>=1)
    {
        if(p&1)ans=ans*x%MOD;
        x=x*x%MOD;
        p>>=1;
    }
    return ans;
}
struct Lift
{
    int n;
    vector<int>tree;
    Lift(int sz){n=sz;tree.assign(n+2,0);}
    void update(int i,int j)
    {
        while(i<=n)
        {
            tree[i]+=j;
            i+=i&-i;
        }
    }
    int query(int i)
    {
        int ans=0;
        while(i>=1)
        {
            ans+=tree[i];
            i-=i&-i;
        }
        return ans;
    }
};
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<int>b=a;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    auto bst=[&](int x)->int
    {
        // if(x<b[0])return 0;
        return lower_bound(b.begin(),b.end(),x)-b.begin()+1;
    };
    vector<int>c(n);
    for(int i=0;i<n;++i)c[i]=bst(a[i]);
    Lift bits(n);
    int inv=0;
    for(int i=n-1;~i;--i)
    {
        inv+=bits.query(c[i]-1);
        bits.update(c[i],1);
    }
    Lift bt(n);
    int sum=0;
    for(int i=0;i<k;++i)
    {
        sum+=bt.query(n)-bt.query(c[i]);
        bt.update(c[i],1);
    }
    /*
        c=1->2->3->4->5->6->7->8
        bits form
        0->1->1->1->1->1->1->1
    */
    int temp=sum,ok=n-k+1;
    for(int i=1;i<ok;++i)
    {
        int low=bt.query(c[i-1]-1);
        sum-=low;
        bt.update(c[i-1],-1);
        // for(int j=0;j<n;++j)cout<<bt.query(j)<<" ";
        // cout<<endl;//0->0->1->1->0->1->1->1
        int high=bt.query(n)-bt.query(c[i+k-1]);
        sum+=high;
        bt.update(c[i+k-1],1);
        temp+=sum;
    }
    // assert(temp%ok==0);
    // temp/=ok;
    int prev=Pow(ok,MOD-2),next=Pow(4,MOD-2);
    // cout<<"prev: "<<prev<<endl;
    // cout<<"next: "<<next<<endl;

    //take last ele
    // for(int i=0;i<n;++i)cout<<c[i]<<" ";
    // cout<<endl;
    int t1=inv%MOD,t2=k*(k-1)%MOD*next%MOD,t3=temp%MOD*prev%MOD;
    // cout<<(inv+k*(k-1)/4-temp*Pow(n-k+1,MOD-2)%MOD+MOD)%MOD;
    int ans=(t1+t2-t3)%MOD;
    if(ans<0)ans+=MOD;
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}