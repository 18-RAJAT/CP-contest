#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    a=abs(a-c);
    b=abs(b-d);
    if(a==0)
    {
        cout<<b<<endl;
        return;
    }
    if(b==0)
    {
        cout<<a<<endl;
        return;
    }
    cout<<a+b+2<<endl;
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