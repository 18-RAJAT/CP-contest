#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a;
    cin>>a;
    cout<<(1LL<<(__builtin_popcountll(a)))<<endl;
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