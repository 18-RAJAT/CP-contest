#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int one=0,mx=0;
    for(int i=0;i<n;++i)
    {
        (s[i]=='1')?one++,mx=max(mx,one):one=0;
    }
    cout<<((s[0]=='1' || s[n-1]=='1' || mx>=2)?"YES":"NO")<<endl;
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