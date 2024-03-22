#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if(n<11 || n-10>=12)
    {
        cout<<0;
    }
    else if(n==20)
    {
        cout<<15;
    }
    else
    {
        cout<<4;
    }
}
signed main()
{
    sol();
    return 0;
}