#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int>mp={{'S',0},{'N',0},{'E',1},{'W',1}};
    string ans(n,'#');
    int plane=0;
    for(int i=0;i<n;++i)
    {
        ans[i]=mp[s[i]]==1?'H':'R';
        ans[i]=='R'?plane|=1:plane|=2;
        mp[s[i]]^=1;
    }
    cout<<((plane>=3 && mp['S']==mp['N'] && mp['E']==mp['W'])?ans:"NO")<<endl;
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