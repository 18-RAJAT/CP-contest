#include<bits/stdc++.h>
using namespace std;
#define int long long
int power(int base,int exp,int mod)
{
    int ans=1;
    base%=mod;
    while(exp>0)
    {
        if(exp&1)ans=(ans*base)%mod;
        exp=exp>>1;
        base=(base*base)%mod;
    }
    return ans;
}

int modInverse(int n,int p)
{
    return power(n,p-2,p);
}

int NcR_mod_P(int n,int r,int p)
{
    if(n<r)return 0;
    if(r==0)return 1;
    int factorial[n+1];
    factorial[0]=1;
    for(int i=1;i<=n;++i)
    {
        factorial[i]=(factorial[i-1]*i)%p;
    }
    return (factorial[n]*modInverse(factorial[r],p)%p*modInverse(factorial[n-r],p)%p)%p;
}

void sol()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n,greater<int>());
    deque<int>dq;
    for(int i=0;i<k;++i)dq.push_back(a[i]);
    int cnt=0;
    for(int i=k;i<n;++i)
    {
        if(dq.back()==a[i])cnt++;
    }
    int temp=dq.back(),count=0;
    for(;!dq.empty() && dq.back()==temp;dq.pop_back())count++;
    cout<<NcR_mod_P(cnt+count,count,1000000007)%1000000007<<endl;
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