#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int l,r;
    cin>>l>>r;
    for(int i=31;i>=0;--i)
    {
        if((1<<i)>=l && (1<<i)<=r)
        {
            cout<<i<<endl;
            break;
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