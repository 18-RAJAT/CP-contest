#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<int,int>mp;
    mp.clear();
    auto convert=[&](int x)->string
    {
        string ans="";
        while(x)
        {
            ans+=x%10+'0';
            x/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    };
    for(int i=1;i<=9;++i)
    {
        int q;
        cin>>q;
        mp[i]=q; 
    }
    for(int i=0;i<n;++i)
    {
        if(convert(mp[s[i]-'0'])>s.substr(i).substr(0,convert(mp[s[i]-'0']).size()))
        {
            int j=i;
            while(j<n && convert(mp[s[j]-'0'])>=convert(s[j]-'0'))
            {
                s[j]=mp[s[j]-'0']+'0';
                j++;
            }
            break;
        }
    }
    cout<<s<<endl;
}
signed main()
{
    sol();
    return 0;
}