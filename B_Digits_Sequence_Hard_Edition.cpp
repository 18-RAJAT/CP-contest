#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    n--;
    int i=1,j=9;
    for(;n-i*j>=0;n-=i*j,i++,j*=10);
    j=j/9+n/i;
    string s=to_string(j);
    cout<<s[n%i];
}
signed main()
{

    sol();
    return 0;
}