#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x;cin>>x;
    cout<<(x%2==0?x/2:(x-3)/2+1)<<endl;
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