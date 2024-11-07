#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>primes={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int Factors(int n)
{
    int ans=0;
    if(n==1)return 0;
    while(n%2==0)
    {
        ans++,n/=2;
    }
    for(int i=3;i*i<=n;i+=2)
    {
        while(n%i==0)
        {
            ans++,n/=i;
        }
    }
    if(n>=2)ans++;
    return ans;
}
int maxi(int n)
{
    if(n==1)return 0;
    int ans=0;
    for(auto& it:primes)
    {
        while(n%it==0)
        {
            ans++,n/=it;
        }
    }
    return ans;
}
int fact(int k)
{
    int ans=0,m=1;
    for(auto& it:primes)
    {
        while(m*it<=k)
        {
            m*=it,ans++;
        }
        if(m==k)break;
    }
    return ans;
}
void sol()
{
    int h,k;
    cin>>h>>k;
    cout<<Factors(h)+fact(k)<<endl;
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