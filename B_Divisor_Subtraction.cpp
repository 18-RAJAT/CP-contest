#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x;
    cin>>x;
    if(x%2==0)
    {
        cout<<x/2;
        return;
    }
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
            x-=i;
            break;
        }
    }
    if(x&1)x-=x;
    cout<<1+x/2;
}
signed main()
{
    sol();
    return 0;
}