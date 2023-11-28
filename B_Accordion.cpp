#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int p1=-1,p2=-1;
    bool ok=false;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='[')
        {
            ok=true;
        }
        if(s[i]==':' && ok==true)
        {
            p1=i;
            break;
        }
    }
    bool ok2=false;
    for(int i=s.size()-1;i>=0;--i)
    {
        if(s[i]==']')
        {
            ok2=true;
        }
        if(s[i]==':' && ok2==true)
        {
            p2=i;
            break;
        }
    }
    int cnt=0;
    if(p1<0 || p2<0 || (p2<=p1))
    {
        cout<<-1<<endl;
        return;
    }
    for(int i=p1;i<=p2;++i)
    {
        if(s[i]=='|')
        {
            cnt++;
        }
    }
    cout<<4+cnt<<endl;
}
signed main()
{
    sol();
    return 0;
}