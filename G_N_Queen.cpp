#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<((x1==x2||y1==y2||abs(x1-x2)==abs(y1-y2))?"Yes":"No")<<endl;
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