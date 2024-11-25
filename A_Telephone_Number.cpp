#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    for(auto& it:s)
    {
        if(it=='8')ans++;
    }
    cout<<((ans>=1 && n-s.find('8')>10)?"YES":"NO")<<endl;
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