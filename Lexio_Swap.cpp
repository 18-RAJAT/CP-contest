#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    vector<pair<char,int>>Ar,Br;
    auto recur=[&](const string& x)
    {
        vector<pair<char,int>>b;
        int l=x.size(),c=1;
        for(int i=1;i<=l;++i)
        {
            if(i<l && x[i]==x[i-1])c++;
            else{b.emplace_back(x[i-1],c);c=1;}
        }
        return b;
    };
    Ar=recur(s);
    Br=recur(t);
    int i=0,j=0;
    int sz=Ar.size(),tz=Br.size();
    bool p=1;
    while(i<sz && j<tz)
    {
        char sc=Ar[i].first,tc=Br[j].first;
        int sl=Ar[i].second,tl=Br[j].second;
        if(sc!=tc || sl<tl){p=0;break;}
        int d=sl-tl;
        if(d%2!=0){p=0;break;}
        i++,j++;
    }
    if(j<tz)p=0;
    while(i<sz)
    {
        if(Ar[i].second%2!=0){p=0;break;}
        i++;
    }
    cout<<(p?"YES":"NO")<<endl;
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