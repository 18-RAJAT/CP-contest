#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,d;
    cin>>n>>d;
    string ans="1 ";
    if(d%3==0 || n>=3)ans+="3 ";
    if(d==5)ans+="5 ";
    if(n>=3)ans+="7 ";
    else if(d==7)ans+="7 ";
    int ok=0;
    if(n>=6)ok=1;
    else if(n>=3 && d%3==0)ok=1;
    else if(n==2 && d==9)ok=1;
    if(ok)ans+="9 ";
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