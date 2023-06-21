#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,ans=0;cin>>n;
        while(n>0)
        {
            ans+=n;n/=2;
        }
        cout<<ans<<"\n";
    }
}