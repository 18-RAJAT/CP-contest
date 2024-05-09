#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    int child=0;
    for(int i=0;i<n;++i)
    {
        char c;
        int d;
        cin>>c>>d;
        if(c=='+') x+=d;
        else
        {
            (x>=d)?x-=d:++child;
        }
    }
    cout<<x<<" "<<child;
}
signed main()
{
    sol();
    return 0;
}

//gcd
int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
//range print 1 10 who is gcd
void print(int n)
{
    for(int i=1;i<=n;++i)
    {
        cout<<i<<" "<<gcd(n,i)<<endl;
    }
}
//gcd of array
int gcd(int a[],int n)
{
    int res=a[0];
    for(int i=1;i<n;++i)
    {
        res=gcd(res,a[i]);
    }
    return res;
}