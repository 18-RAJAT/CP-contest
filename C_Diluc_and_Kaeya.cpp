#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b)
{
    return (b==0)?a:gcd(b,a%b);
}
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<pair<int,int>,int>mp;
    vector<int>ans(n);
    int d_count=0,k_count=0;
    for(int i=0;i<n;++i)
    {
        (s[i]=='D')?d_count++:k_count++;
        pair<int,int>normalized={d_count/gcd(d_count,k_count),k_count/gcd(d_count,k_count)};
        ans[i]=++mp[normalized];
    }
    for(int i=0;i<n;++i)
    {
        cout<<ans[i]<<" ";
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