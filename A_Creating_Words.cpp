#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string a,b;
    cin>>a>>b;
    swap(a[0],b[0]);
    cout<<a<<" "<<b<<endl;
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