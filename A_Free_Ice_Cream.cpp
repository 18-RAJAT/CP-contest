#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    int child=0;
    for(int i=0;i<n;++i)
    {
        char c;
        int d;
        cin>>c>>d;
        if(c=='+') x+=d;
        else
        {
            (x>=d)?x-=d:++child;
        }
    }
    cout<<x<<" "<<child;
}
signed main()
{
    sol();
    return 0;
}