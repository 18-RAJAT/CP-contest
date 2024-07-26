#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b;
    cin>>a>>b;
    int c=0;
    while(a>=b)
    {
        a-=b,a++,c+=b;
    }
    cout<<a+c;
}
signed main()
{
    sol();
    return 0;
}