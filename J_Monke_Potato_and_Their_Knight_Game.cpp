#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<((x1+y1)%2==(x2+y2)%2?"Potato":"Monke")<<endl;
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