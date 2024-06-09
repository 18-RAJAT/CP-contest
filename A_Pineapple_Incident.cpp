#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int t,s,x;
    cin>>t>>s>>x;
    if(x<t)cout<<"NO";
    else if(x==t)cout<<"YES";
    else
    {
        int p=x-t;
        cout<<((p%s==0 || p>s && p%s==1)?"YES":"NO");
    }
}
signed main()
{
    sol();
    return 0;
}