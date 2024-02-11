#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b;
    cin>>a>>b;
    if(a>b)
    {
        swap(a,b);
    }
    if(a%2==0)
    {
        cout<<"Yes"<<endl;
    }
    else if(b%2==0 && b/2!=a)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
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