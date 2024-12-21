#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b && b==c)
    {
        cout<<"Yes"<<endl;
        return;
    }
    if(a==b || b==c || a==c)
    {
        cout<<"Yes"<<endl;
        return;
    }
    if(a+b==c || a+c==b || b+c==a)
    {
        cout<<"Yes"<<endl;
        return;
    }
    cout<<"No"<<endl;
}
signed main()
{
    sol();
    return 0;
}