#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l=0,r=n-1;
    while(l<n && s[l]=='B')
    {
        l++;
    }
    while(r>=0 && s[r]=='A')
    {
        r--;
    }
    if(l==n || r==-1 || l>r)
    {
        cout<<0<<endl;
        // return;
    }
    else
    {
        cout<<r-l<<endl;
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