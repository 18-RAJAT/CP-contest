#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    char position='a'+(n%26);
    cout<<((position=='l' || position=='o' || position=='y' || position=='a' || position=='i' || position=='x')?"HAPPY":"SAD");
}
signed main()
{
    sol();
    return 0;
}