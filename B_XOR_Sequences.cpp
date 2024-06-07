#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x,y;
    cin>>x>>y;
    for(int i=0;i<32;++i)
    {
        if((x&(1LL<<i))!=(y&(1LL<<i)))
        {
            cout<<(1LL<<i)<<endl;
            return;
        }
    }
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