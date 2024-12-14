#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int l,r;
    cin>>l>>r;
    if(l==r)
    {
        cout<<0;
        return;
    }
    for(int i=62;~i;--i)
    {
        if((l&(1LL<<i))!=(r&(1LL<<i)))
        {
            cout<<(1LL<<(i+1))-1;
            return;
        }
    }
}
signed main()
{
    sol();
    return 0;
}