#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,a,b;
    cin>>n>>a>>b;
    if(a<=b-n+1)cout<<(b-n+1+b)*n/2<<endl;
    else if(a>=b)cout<<n*a<<endl;
    else cout<<(a+b)*(b-a+1)/2+(n-b+a-1)*a<<endl;
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