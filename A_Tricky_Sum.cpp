#include<bits/stdc++.h>
using namespace std;
#define int long long
int calc(int n)
{
    int pow2=1,ans=0;
    while(pow2<=n)
    {
        ans+=pow2,pow2*=2;
    }
    return ans;
}
void sol()
{
    int n;
    cin>>n;
    cout<<(n*(n+1)/2)-(2*calc(n))<<endl;
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