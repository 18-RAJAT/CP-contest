#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int vasya=max(3*a/10,a-a/250*c);
    int misha=max(3*b/10,b-b/250*d);
    if(vasya>misha)
    {
        cout<<"Misha"<<endl;
    }
    else if(misha>vasya)
    {
        cout<<"Vasya"<<endl;
    }
    else
    {
        cout<<"Tie"<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}