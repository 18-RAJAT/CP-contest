#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    int ans=0;
    for(int i=0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            int x1=i==0?a1:a2;
            int x2=i==0?a2:a1;
            int y1=j==0?b1:b2;
            int y2=j==0?b2:b1;
            int ok=0;
            if(x1>y1)ok++;
            if(x2>y2)ok++;
            if(ok>=2)ans++;
        }
    }
    cout<<ans<<endl;
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