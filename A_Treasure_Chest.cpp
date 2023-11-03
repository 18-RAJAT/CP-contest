#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x,y,k;
    cin>>x>>y>>k;
    auto chk=[&](int a,int b)->int
    {
        return abs(a-b);
    };
    int ans1=0,ans2=0;
    ans1+=x,ans2+=y;
    if(k>=chk(x,y))
    {
        ans1+=chk(x,y),ans2+=chk(x,y);
    }
    else
    {
        ans1+=(chk(x,y)*2)-k,ans2+=chk(x,y);
    }
    cout<<min(ans1,ans2)<<endl;   
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