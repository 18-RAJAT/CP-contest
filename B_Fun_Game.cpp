#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    s+='1',t+='1';
    int find_one=s.find('1');
    cout<<((s.substr(0,find_one)==t.substr(0,find_one))?"YES":"NO")<<endl;
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