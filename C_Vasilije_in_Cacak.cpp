#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k,x;
    cin>>n>>k>>x;
    int vals=n-k+1+n;
    int val=vals*k/2;
    cout<<((k*(k+1)/2>x || val<x)?"NO":"YES")<<endl;
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