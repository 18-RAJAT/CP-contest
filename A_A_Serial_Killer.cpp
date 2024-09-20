#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string a,b;
    cin>>a>>b;
    cout<<a<<" "<<b<<endl;
    int n;
    cin>>n;
    while(n--)
    {
        string s,t;
        cin>>s>>t;
        (a==s)?a=t:b=t;
        cout<<a<<" "<<b<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}