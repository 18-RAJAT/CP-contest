#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    cout<<min((m-n%m)*a,(n%m)*b);
}
signed main()
{
    sol();
    return 0;
}