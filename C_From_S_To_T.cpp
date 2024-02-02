#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string a,b,c;
    cin>>a>>c>>b;
    map<char,int>mp1,mp2;
    mp1.clear(),mp2.clear();
    for(int i=0;i<a.size();++i)
    {
        mp1[a[i]]++;
    }
    for(int i=0;i<b.size();++i)
    {
        mp1[b[i]]++;
    }
    for(int i=0;i<c.size();++i)
    {
        mp2[c[i]]++;
    }
    function<bool(string,string,int,int)>isSubSequence=[&](string str1,string str2,int m,int n)->bool
    {
        if(m==0)
        {
            return true;
        }
        if(n==0)
        {
            return false;
        }
        if(str1[m-1]==str2[n-1])
        {
            return isSubSequence(str1,str2,m-1,n-1);
        }
        return isSubSequence(str1,str2,m,n-1);
    };
    bool ok=true;
    for(char i='a';i<='z';++i)
    {
        if(mp1[i]<mp2[i])
        {
            ok=false;
            break;
        }
    }
    cout<<(ok && isSubSequence(a,c,a.size(),c.size())?"YES\n":"NO\n");
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