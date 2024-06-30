#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1>y1)swap(x1,y1),swap(x2,y2);
    cout<<(x2<y2?"YES":"NO")<<endl;
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