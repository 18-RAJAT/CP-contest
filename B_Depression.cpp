#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int H,M;
    char ch;
    cin>>H>>ch>>M;
    H%=12;
    cout<<30.0*H+M/2.0<<' '<<6*M<<endl;
}
signed main()
{
    sol();
    return 0;
}