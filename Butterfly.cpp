#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int r,g,b;
    cin>>r>>g>>b;
    int maximum=max({r,g,b});
    int calc=r+g+b-maximum;
    if(calc<maximum)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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