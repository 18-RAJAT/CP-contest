#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string a,b,a1,b1;
    cin>>a>>b;
    a1=string(b.size(),'0')+a,b1=string(a.size(),'0')+b;
    if(a1>b1)cout<<">";
    else if(a1<b1)cout<<"<";
    else cout<<"=";
}
signed main()
{
    sol();
    return 0;
}