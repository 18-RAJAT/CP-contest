#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans="";
    // random_shuffle(s.begin(),s.end());
    int sum=0,pos=0;
    auto convert=[](char ch)->int
    {
        return ch-'0';
    };
    reverse(s.begin(),s.end());
    for(int i=0;i<n;++i)
    {
        sum+=convert(s[i]);
    }
    for(int i=0;i<n;++i)
    {
        char temp='0';
        int curr=sum+pos;
        temp+=((curr)%10);
        pos=(curr)/10;
        sum-=convert(s[i]);
        ans.push_back(temp);
    }
    function<void(string&)>remove_zero=[&](string& s)->void
    {
        while(s.back()=='0')
        {
            s.pop_back();
        }
    };
    string change=to_string(pos);
    reverse(ans.begin(),ans.end());
    if(change=="1")
    {
        cout<<change<<ans<<endl;
    }
    // else if(change=="0")
    // {
    //     cout<<ans<<endl;
    // }
    else
    {
        reverse(ans.begin(),ans.end());
        int last=ans.back();
        while(last=='0')
        {
            ans.pop_back();
            last=ans.back();
        }
        reverse(ans.begin(),ans.end());
        // cout<<change<<ans<<endl;
        cout<<ans<<endl;
    }
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