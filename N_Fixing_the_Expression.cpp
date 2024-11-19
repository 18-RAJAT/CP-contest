#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    char x=s[0],y=s[1],z=s[2];
    auto check=[&](char a,char b,char c)
    {
        if(b=='<')return a<c;
        if(b=='>')return a>c;
        if(b=='=')return a==c;
        return false;
    };
    if(check(x,y,z))
    {
        cout<<s<<endl;
        return;
    }
    int ok=0;
    if(y=='=')
    {
        for(auto& it:{'<','>'})
        {
            if(it==y)continue;
            if(check(x,it,z))
            {
                s[1]=it;
                cout<<s<<endl;
                return;
            }
        }
    }
    if(y!='=' && !ok)
    {
        for(char c='0';c<='9';++c)
        {
            if(c==x)continue;
            string temp=s;
            temp[0]=c;
            if(check(temp[0],temp[1],temp[2]))
            {
                cout<<temp<<endl;
                return;
            }
        }
    }
    if(y!='=' && !ok)
    {
        for(char c='0';c<='9';++c)
        {
            if(c==z)continue;
            string temp=s;
            temp[2]=c;
            if(check(temp[0],temp[1],temp[2]))
            {
                cout<<temp<<endl;
                return;
            }
        }
    }
    if(y!='=' && !ok)
    {
        for(char c='0';c<='9';++c)
        {
            if(c==z)continue;
            string temp=s;
            temp[2]=c;
            if(check(temp[0],temp[1],temp[2]))
            {
                cout<<temp<<endl;
                return;
            }
        }
    }
    for(auto& it:{'<','>','='})
    {
        if(it==y)continue;
        if(check(x,it,z))
        {
            s[1]=it;
            cout<<s<<endl;
            return;
        }
    }
    cout<<s<<endl;
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