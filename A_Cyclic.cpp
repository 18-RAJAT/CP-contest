#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a=n/100,b=(n/10)%10,c=n%10;
    cout<<b*100+c*10+a<<" "<<c*100+a*10+b;
}
signed main()
{
    sol();
    return 0;
}