#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        int ans=0;

        // for(int i=1;i<=n;++i)
        for(int i=0;i<n;++i)
        {
            int x;
            cin>>x;
            // ans=__gcd(abs(x-i),ans); or 
            ans=__gcd(abs(i+1-x),ans);
        }
        cout<<ans<<"\n";
    }
    return 0;
}