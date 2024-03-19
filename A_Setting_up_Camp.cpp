#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(c<(3-b%3)%3==1)
    {
        cout<<"-1"<<endl;
        return;
    }
    cout<<a+(b+c)/3+bool((b+c)%3)<<endl;
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