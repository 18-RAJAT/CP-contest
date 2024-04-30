#include<bits/stdc++.h>
using namespace std;
const long long int M=2e6+10;
long long int n,k;
long long int a[M],b[M];
bool ok(long long int x)
{
    long long int sum=0;
    for(long long int i=1;i<=n;++i)
    {
        sum+=max(x-a[i],0LL);
    }
    return sum<=k;
}
void sol()
{
    cin>>n>>k;
    for(long long int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    long long int r=0;
    for(long long int i=40;i>=0;--i)
    {
        if(ok(r+(1LL<<i)))
        {
            r+=(1LL<<i);
        }
    }
    for(long long int i=1;i<=n;++i)
    {
        if(a[i]<r)
        {
            k-=(r-a[i]);
            a[i]=r;
        }
    }
    long long int c=0;
    for(long long int i=1;i<=n;++i)
    {
        c+=(a[i]>r);
    }
    cout<<r*n+c+k-n+1<<endl;
}
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}