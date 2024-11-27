#include <bits/stdc++.h>
using namespace std;
#define int long long

pair<string,int>recur(string& pos)
{
    int ans=0;
    for(auto& it:pos)
    {
        if(isdigit(it))
        {
            ans=ans*10+(it-'0');
        }
    }
    return {pos.substr(0,3),ans};
}
int minStairs(int st,int en,bool res)
{
    if(res)
    {
        return abs(st-en);
    }
    else
    {
        vector<int>pairs={1,2,3,5};
        int mn=LLONG_MAX;
        for(auto& it:pairs)
        {
            int stairs=abs(st-it)+abs(en-it);
            mn=min(mn,stairs);
        }
        return mn;
    }
}

signed main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        string s;
        cin>>s;
        int hyphen=s.find('-');
        string st=s.substr(0,hyphen),en=s.substr(hyphen+1);
        pair<string,int>start=recur(st),end=recur(en);
        bool res=start.first==end.first;
        int ans=minStairs(start.second,end.second,res);
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}