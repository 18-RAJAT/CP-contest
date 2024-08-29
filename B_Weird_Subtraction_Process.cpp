#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b;
    cin>>a>>b;
    while(a && b)
    {
        if(a>=2*b)a%=2*b;
        else if(b>=2*a)b%=2*a;
        else break;
    }
    cout<<a<<" "<<b;
}
signed main()
{
    sol();
    return 0;
}