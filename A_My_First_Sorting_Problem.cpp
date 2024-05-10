#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x,y;
    cin>>x>>y;
    cout<<min(x,y)<<" "<<max(x,y)<<endl;
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