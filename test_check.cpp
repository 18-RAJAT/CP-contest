#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x,y,z;
    cin>>x>>y>>z;
    int step=0;
    step=step+2*abs(z);
    step=step+abs(x);
    cout<<step;
}
signed main()
{
    sol();
    return 0;
}