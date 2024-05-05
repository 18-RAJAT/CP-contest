#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int l,r;
    cin>>l>>r;
    int cnt=l,ans=1;
    while(cnt*2<=r)
    {
        ans++,cnt*=2;
    }
    cnt/=l;
    int res=r/cnt-l+1;
    cnt/=2,cnt*=3;
    res+=max(0LL,(r/cnt-l+1)*(ans-1));
    cout<<ans<<" "<<res<<endl;
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