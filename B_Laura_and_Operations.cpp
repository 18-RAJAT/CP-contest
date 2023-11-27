#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,c;
    cin>>a>>b>>c;
    int x=0,y=0,z=0;
    if(abs<int>(b-c)%2==0)
    {
        x=1;
    }
    if(abs<int>(a-c)%2==0)
    {
        y=1;
    }
    if(abs<int>(a-b)%2==0)
    {
        z=1;
    }
    cout<<x<<" "<<y<<" "<<z<<endl;
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