#include<bits/stdc++.h>
using namespace std;
#define int long long
int sol()
{
    int n;
    cin>>n;
    int p=1LL<<(int)(ceil(log2(n+1.0)));
    cout<<p-1<<endl;
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