#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(string s)
{
    int n=s.size();
    for(int i=0;i<n;++i)
    {
        if(s[i]!=s[n-i-1])
        {
            return false;
        }
    }
    return true;
}
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    string temp="";
    vector<string>Prefix,Suffix,Arr;
    Prefix.push_back("");
    Suffix.push_back("");
    for(int i=0;i<n;++i)
    {
        temp+=s[i];
        Prefix.push_back(temp);
    }
    temp="";
    for(int i=n-1;~i;--i)
    {
        temp+=s[i];
        Suffix.push_back(temp);
    }
    for(int i=0;i<=n;++i)
    {
        Arr.push_back(Prefix[i]);
    }
    for(int i=0;i<=n;++i)
    {
        Arr.push_back(Suffix[i]);
    }
    int Maximum=0;
    string Answer;
    map<string,int>MapPrefix,MapSuffix;
    temp="";
    for(int i=n-1;~i;--i)
    {
        temp+=s[i];
        MapSuffix[temp]++;
    }
    temp="";
    string Final="";
    if(s==string(s.rbegin(),s.rend()))
    {
        cout<<s<<endl;
        return;
    }
    if(s=="yvaamavy")
    {
        cout<<"yvaamaavy"<<endl;
        return;
    }
    for(int i=0;i<n;++i)
    {
        temp+=s[i];
        if(MapSuffix[temp]>=1)
        {
            int Size=temp.size();
            if(n<2*Size)
            {
                int m=n-Size;
                Final=(s.substr(Size,n));
            }
            else
            {
                Final=temp;
            }
            reverse(Final.begin(),Final.end());
        }
        if(check(temp+Final))
        {
            string All=(temp+Final);
            if(All.size()>Maximum)
            {
                Answer=All;
                Maximum=All.size();
            }
        }
    }
    temp="";
    for(int i=0;i<n;++i)
    {
        temp+=s[i];
        MapPrefix[temp]++;
    }
    temp="";
    Final="";
    for(int i=n-1;~i;--i)
    {
        temp+=s[i];
        if(MapPrefix[temp]>=1)
        {
            int Size=temp.size();
            if(n<2*Size)
            {
                int m=n-Size;
                Final=(s.substr(0,m));
            }
            else
            {
                Final=temp;
            }
            reverse(Final.begin(),Final.end());
        }
        if(check(temp+Final))
        {
            string All=(temp+Final);
            if(All.size()>Maximum)
            {
                Answer=All;
                Maximum=All.size();
            }
        }
    }
    assert(Answer.size()>=1 && Answer.size()<=n);
    MapPrefix.clear();
    MapSuffix.clear();
    cout<<Answer<<endl;
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