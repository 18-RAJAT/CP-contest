#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"1";
    }
    else
    {
        cout<<(n*n)+((n-1)*(n-1));
    }
}
signed main()
{
    sol();
    return 0;
}