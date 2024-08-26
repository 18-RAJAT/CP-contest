#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<char>ch;
    int count=0,ok=0;
    string ans="";
    for(int i=0;i<n;++i)
    {
        if(s[i]=='(' && count<k/2)
        {
            ch.push_back(s[i]);
            ans+=s[i],count++;
        }
        if(s[i]==')' && ch.size()>=1)
        {
            ch.pop_back();
            ans+=s[i],ok++;
        }
        if(count==k/2 && ok==k/2)break;
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}