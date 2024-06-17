#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x,y;
    cin>>x>>y;
    int ans=0;
    int a[3]={y,y,y};
    while(*min_element(a,a+3)<x)
    {
        int idx =min_element(a,a+3)-a;
        int update=min(x,a[(idx+1)%3]+a[(idx+2)%3]-1);
        a[idx]=update,ans++;
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}