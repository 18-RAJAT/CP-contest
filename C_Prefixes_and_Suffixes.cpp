#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<string>s,v;
    for(int i=0;i<2*n-2;++i)
    {
        string a;
        cin>>a;
        if(a.size()==n-1)
        {
            s.push_back(a);
        }
        v.push_back(a);
    }
    string t=s[0];
    string p=s[1];
    p+=t[n-2];
    string temp="";
    map<string,int>prefix,suffix;
    for(int i=0;i<n;++i)
    {
        temp+=p[i];
        prefix[temp]++;
    }
    temp="";
    for(int i=n-1;~i;--i)
    {
        temp+=p[i];
        reverse(temp.begin(),temp.end());
        suffix[temp]++;
        reverse(temp.begin(),temp.end());
    }
    string ans="";
    for(int i=0;i<2*n-2;++i)
    {
        if(prefix[v[i]]>0)
        {
            ans+='P';
            prefix[v[i]]--;
        }
        else if(suffix[v[i]]>0)
        {
            ans+='S';
            suffix[v[i]]--;
        }
    }
    for(auto &val:prefix)
    {
        if(val.second>0)
        {
            ans+='P';
            break;
        }
    }
    for(auto &val:suffix)
    {
        if(val.second>0)
        {
            ans+='S';
            break;
        }
    }
    if(ans.size()==n)
    {
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<2*n-2;++i)
    {
        if(prefix[v[i]]>0)
        {
            ans+='P';
            prefix[v[i]]--;
        }
        else if(suffix[v[i]]>0)
        {
            ans+='S';
            suffix[v[i]]--;
        }
    }
    p.pop_back();
    t+=p[n-2];
    prefix.clear();
    suffix.clear();
    temp="";
    ans="";
    for(int i=0;i<n;++i)
    {
        temp+=t[i];
        prefix[temp]++;
    }
    temp="";
    for(int i=n-1;~i;--i)
    {
        temp+=t[i];
        reverse(temp.begin(),temp.end());
        suffix[temp]++;
        reverse(temp.begin(),temp.end());
    }
    // cout<<"t: "<<t<<endl;
    // cout<<"p: "<<p<<endl;
    for(int i=0;i<2*n-2;++i)
    {
        if(prefix[v[i]]>0)
        {
            ans+='P';
            prefix[v[i]]--;
        }
        else if(suffix[v[i]]>0)
        {
            ans+='S';
            suffix[v[i]]--;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}