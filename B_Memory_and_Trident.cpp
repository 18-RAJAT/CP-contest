#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    if(s.size()&1){cout<<"-1";return;}
    int l=0,r=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='L')l++;
        else if(s[i]=='R')l--;
        else if(s[i]=='U')r++;
        else if(s[i]=='D')r--;
    }
    cout<<(abs(l)+abs(r))/2;
}
signed main()
{
    sol();
    return 0;
}