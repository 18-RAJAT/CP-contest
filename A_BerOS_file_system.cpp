#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='/' && s[i+1]=='/')s.erase(i+1,1),i--;
        if(i==s.size()-1 && s[i]=='/' && s.size()!=1)s.erase(i,1);
    }
    cout<<s;
}
signed main()
{
    sol();
    return 0;
}