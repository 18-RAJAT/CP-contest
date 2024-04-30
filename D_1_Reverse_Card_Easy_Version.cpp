#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int temp=n;
    for(int i=2;i<=m;++i)
    {
        int mul=(i*i);
        int card=(n+i)/mul;
        temp+=card;
    }
    cout<<temp<<endl;
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