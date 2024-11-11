#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
void sol()
{
    int n,b,c;
    cin>>n>>b>>c;
    if(n<=c)
    {
        cout<<n<<endl;
        return;
    }
    if(b==0)
    {
        cout<<(c+1<n-1?-1:n-1)<<endl;
        return;
    }
    int permute=ceil((double)(n-c)/b);
    cout<<max(n-permute,0LL)<<endl;
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