#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if(n-3>=0 && (n-3)%2==0 && (n-3)/2>0)
    {
        cout<<"1 "<<(n-3)/2<<endl;
        return;
    }
    cout<<"NO"<<endl;
}
signed main()
{
    sol();
    return 0;
}