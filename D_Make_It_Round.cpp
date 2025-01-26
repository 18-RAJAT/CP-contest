#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int ans=n*m;
    for(int i=10;i<=100000000000000000;i*=10)
    {
        int g=__gcd(i,n),x=i/g;
        if(x<=m)x*=(m/x),ans=n*x;
    }
    cout<<ans<<endl;
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