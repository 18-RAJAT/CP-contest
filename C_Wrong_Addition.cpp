#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s,t;
    cin>>s>>t;
    while(s.size()<t.size())
    {
        s="0"+s;
    }
    string ans;
    while(!s.empty())
    {
        if(t.empty())
        {
            if(s.back()!='0')
            {
                ans="1-";
                break;
            }
            s.pop_back();
            continue;
        }
        char cs=t.back(),ca=s.back();
        t.pop_back();
        s.pop_back();
        if(ca<=cs)
        {
            ans+=(char)(cs-ca+'0');
            continue;
        }
        if(t.empty()||t.back()!='1')
        {
            ans="1-";
            break;
        }
        t.pop_back();
        ans+=(char)(10-(ca-'0')+cs-'0'+'0');
    }
    while(!ans.empty()&&ans.back()=='0')
    {
        ans.pop_back();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<"\n";
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