#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a=1,b=0,alice=0,bob=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='A')
        {
            (a==1)?alice++:(b=0,a=1);
        }
        else
        {
            (b==1)?bob++:(a=0,b=1);
        }
    }
    cout<<alice<<" "<<bob<<endl;
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