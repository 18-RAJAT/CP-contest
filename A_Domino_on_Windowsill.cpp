#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k1,k2,w,b;
    cin>>n>>k1>>k2>>w>>b;
    cout<<(((2*w)<=k1+k2 && (2*b)<=((n-k1)+(n-k2)))?"YES":"NO")<<endl;
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