#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,a,b;
    cin>>n>>a>>b;
    cout<<((abs(a-b)%2==0)?"YES":"NO")<<endl;
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