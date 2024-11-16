#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int q;
    cin>>q;
    vector<int>a(q);
    for(int i=0;i<q;++i)cin>>a[i];
    vector<int>ans;
    ans.push_back(s.size());
    for(int i=1;i<=60;++i)
    {
        if(2*ans.back()>(int)1e18)ans.push_back(1e18+1);
        else ans.push_back(2*ans.back());
    }
    auto convert=[&](char c)->char
    {
        return islower(c)?toupper(c):tolower(c);
    };
    auto kth=[&](auto& ch,int k,int l)->char
    {
        if(l==0)return s[k-1];
        if(k<=ans[l-1])return ch(ch,k,l-1);
        else
        {
            int nw=k-ans[l-1];
            char c=ch(ch,nw,l-1);
            return convert(c);
        }
    };
    string res="";
    for(int i=0;i<q;++i)
    {
        if(a[i]>ans.back())
        {
            res+="?";
            res+=" ";
            continue;
        }
        char c=kth(kth,a[i],60);
        res+=c;
        res+=" ";
    }
    cout<<res;
}
signed main()
{
    sol();
    return 0;
}