#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,k;
    cin>>a>>k;
    k--;
    while(k--)
    {
        int mn=INT_MAX,mx=INT_MIN;
        int x=a;
        while(x)
        {
            mn=min(mn,x%10);
            mx=max(mx,x%10);
            x/=10;
        }
        if(mn==0)
        {
            break;
        }
        a+=mn*mx;
    }
    cout<<a<<endl;
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