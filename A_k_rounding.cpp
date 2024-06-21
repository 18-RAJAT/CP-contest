#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
void sol()
{
    int n,k;
    cin>>n>>k;
    int ans=1;
    for(int i=0;i<k;++i)ans*=10;
    cout<<lcm(n,ans);
}
signed main()
{
    sol();
    return 0;
}