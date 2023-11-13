#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    function<int(int,int)>gcd=[&](int x,int y)->int
    {
        if(y==0)
        {
            return x;
        }
        return gcd(y,x%y);
    };
    int g=gcd(x,y);
    x/=g;
    y/=g;
    cout<<min(a/x,b/y)<<endl;
}
signed main()
{
    sol();
    return 0;
}