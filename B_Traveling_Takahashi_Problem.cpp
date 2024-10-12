#include<bits/stdc++.h>
using namespace std;
#define int long long

void sol()
{
    int n;
    cin>>n;
    vector<array<int,2>>points(n);
    for(int i=0;i<n;++i)
    {
        cin>>points[i][0]>>points[i][1];
    }
    auto Travel=[&](int x1,int y1,int x2,int y2)
    {
        return sqrt(1LL*(x1-x2)*(x1-x2)+1LL*(y1-y2)*(y1-y2));
    };
    double ans=0;
    ans+=Travel(0,0,points[0][0],points[0][1]);
    for(int i=1;i<n;++i)ans+=Travel(points[i-1][0],points[i-1][1],points[i][0],points[i][1]);
    ans+=Travel(points[n-1][0],points[n-1][1],0,0);
    cout<<fixed<<setprecision(20)<<ans;
}
signed main()
{
    sol();
    return 0;
}