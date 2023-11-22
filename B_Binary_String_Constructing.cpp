#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,x;
    cin>>a>>b>>x;
    string s="";
    if(a>b)
    {
        swap(a,b);
        s+='0';
        a--;
    }
    else
    {
        s+='1';
        b--;
    }
    for(int i=0;i<x;++i)
    {
        if(s.back()=='0')
        {
            s+='1';
            b--;
        }
        else
        {
            s+='0';
            a--;
        }
    }
    for(int i=0;i<a;++i)
    {
        s='0'+s;
    }
    for(int i=0;i<b;++i)
    {
        s+='1';
    }
    sort(s.begin(),s.end(),greater<char>());
    cout<<s<<endl;
}
signed main()
{
    sol();
    return 0;
}