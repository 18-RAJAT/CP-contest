#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans=1;
        for(int i=3;i<=2*n;++i)
        {
            ans*=i;
            ans%=1000000007;
        }
        cout<<ans<<"\n";
    }
}