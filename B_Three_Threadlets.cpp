#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
void sol()
{
    vector<int>a(3);
    for(int i=0;i<3;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    for(auto&it:a)
    {
        ans=gcd(ans,it);
    }
    int cnt=0;
    for(auto&it:a)
    {
        cnt+=it/ans-1;
    }
    cout<<(cnt<4?"YES":"NO")<<endl;
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