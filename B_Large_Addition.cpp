#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int ok=s[0]=='1' && s.back()<'9';
    for(int i=1;i+1<s.size();++i)ok&=s[i]>'0';
    cout<<(ok?"YES":"NO")<<endl;
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