#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int ok=0,x,y;
    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s>>x>>y;
        if(x>=2400 && x<y)ok=1;
    }
    cout<<(ok?"YES":"NO");
}
signed main()
{
    sol();
    return 0;
}