#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x(n+1),y(n+1),ans(0);
        while(n--)
        {
            int a;
            cin>>a;
            if(a<x)
            {
                x=a;
            }
            else if(a<y)
            {
                ans++;
                y=a;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}