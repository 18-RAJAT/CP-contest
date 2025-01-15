#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"a"<<endl;
        return;
    }
    if(n&1)
    {
        string s((n-3)/2,'a');
        cout<<s<<"bc"<<s<<"a"<<endl;
    }
    else
    {
        string s((n-2)/2,'a');
        cout<<s<<"b"<<s<<"a"<<endl;
    }
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