#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,a,b;
    cin>>n>>a>>b;
    cout<<((a*2<=b)?n*a:(n/2)*b+(n&1)*a)<<endl;
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