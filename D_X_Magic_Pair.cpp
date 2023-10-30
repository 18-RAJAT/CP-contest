#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,x;
    cin>>a>>b>>x;
    while(a&&b)
    {
        if(a<b)
        {
            swap(a,b);
        }
        if(a>=x && (a-x)%b==0 || a==x || a%b==x)
        {
            cout<<"YES\n";
            return;
        }
        a%=b;
    }
    cout<<"NO\n";
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