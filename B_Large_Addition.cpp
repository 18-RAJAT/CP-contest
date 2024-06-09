#include<bits/stdc++.h>
using namespace std;
#define int long long
bool recur(const string& s)
{
    string f="01234";
    string l="56789";
    return s.find(f)!=string::npos && s.find(l)!=string::npos;
}
void sol()
{
    int n;
    cin>>n;
    string s=to_string(n);
    if (recur(s))
    {
        cout<<"NO"<<endl;
        return;
    }
    int ok=0,sum=0,tot=5+6+7+8+9;
    for(int i =0;i<s.size()-1;++i)
    {
        sum+=(s[i]-'0');
        if(s[i]=='0')ok=1;
    }
    if(s.back()=='9'||sum==tot||s[0]!='1'||s.size()%10==0 || ok)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
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