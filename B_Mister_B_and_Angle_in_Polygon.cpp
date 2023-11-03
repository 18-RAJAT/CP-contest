#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,a;
    cin>>n>>a;
    function<int(int)>polygon_sides=[&](int n)
    {
        return min(n,max(3ll,(n*a+90)/180+2));
    };
    int v1=2,v2=1,v3=0;
    v3=polygon_sides(n);
    cout<<v1<<" "<<v2<<" "<<v3<<"\n";
}
signed main()
{
    sol();
    return 0;
}