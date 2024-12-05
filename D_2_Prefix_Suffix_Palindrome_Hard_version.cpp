#include<bits/stdc++.h>
using namespace std;
#define int long long
char str[1000001];
int pali;
void Manacher(string s)
{
    string t="#";
    for(auto& c:s)
    {
        t+="#";
        t+=c;
    }
    t+="#&";
    int n=t.size(),l=0,r=0,p[n];
    fill(p,p+n,0);
    for(int i=1;i<n-1;++i)
    {
        p[i]=(i<r)?min(r-i,p[l+r-i]):0;
        while(t[i+1+p[i]]==t[i-1-p[i]])p[i]++;
        if(i+p[i]>r)
        {
            l=i-p[i];
            r=i+p[i];
        }
    }
    int maxi=0,center=0;
    for(int i=1;i<n-1;++i)
    {
        if(p[i]>maxi)
        {
            maxi=p[i];
            center=i;
        }
    }
    string val="";
    for(int i=center-maxi+1;i<center+maxi;i+=2)
    {
        val+=t[i];
    }
    if(val.size()>pali)
    {
        pali=val.size();
        for(int i=0;i<val.size();++i)str[i]=val[i];
    }
}
void sol()
{
    string s;
    cin>>s;
    int cnt=0,n=s.size();
    for(int i=0;i<n;++i)
    {
        if(s[i]!=s[n-i-1])break;
        cnt++;
    }
    cout<<s.substr(0,cnt);
    string x("");
    for(int i=cnt;i<n-cnt;++i)
    {
        x+=s[i];
    }
    Manacher(x);
    reverse(x.begin(),x.end());
    Manacher(x);
    for(int i=0;i<pali;++i)cout<<str[i];
    if(n-cnt-1>=0)cout<<s.substr(n-cnt,cnt);
    cout<<endl;
    pali=0;
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