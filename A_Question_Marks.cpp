#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int>mp;
    int ans=0;
    for(int i=0;i<n*4;++i)mp[s[i]]++;
    int a=mp['A'];
    int b=mp['B'];
    int c=mp['C'];
    int d=mp['D'];
    ans+=min(n,a);
    ans+=min(n,b);
    ans+=min(n,c);
    ans+=min(n,d);
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