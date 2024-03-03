#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    if(k==1)
    {
        cout<<n<<endl;
        return;
    }
    bitset<10>bs;
    int x=n;
    while(1)
    {
        bs.reset();
        int y=x;
        while(y)
        {
            bs[y%10]=1;
            y/=10;
        }
        if(bs.count()<=k)
        {
            cout<<x<<endl;
            return;
        }
        x+=n;
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