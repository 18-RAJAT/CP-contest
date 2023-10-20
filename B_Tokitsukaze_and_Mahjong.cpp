#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s[3];
    cin>>s[0]>>s[1]>>s[2];
    int ans=3;
    auto check=[&](string a,string b,string c)->int
    {
        int res=0;
        if(a==b)
        {
            res++;
        }
        if(a==c)
        {
            res++;
        }
        if(b==c)
        {
            res++;
        }
        return res;
    };
    // if(check(s[0],s[1],s[2])==3)
    // {
    //     ans=0;
    // }
    // if(check(s[0],s[1],s[2])==2)
    // {
    //     ans=1;
    // }
    // if(check(s[0],s[1],s[2])==1)
    // {
    //     ans=2;
    // }
    if(s[0]==s[1] && s[1]==s[2] && s[0]==s[2])
    {
        ans=0;
    }
    else if(s[0]==s[1] || s[0]==s[2] || s[1]==s[2])
    {
        ans=1;
    }
    else
    {
        ans=2;
    }
    for(auto A='1';(char)A+2<='9';++A)
    {
        for(auto& B:{'m','s','p'})
        {
            string x1="",x2="",x3="";
            
            x1+=A,x1+=B;

            x2+=char(A+1),x2+=B;x

            x3+=char(A+2),x3+=B;
            int cnt=0;
            if(x1!=s[0] && x1!=s[1] && x1!=s[2])
            {
                cnt++;
            }
            if(x2!=s[0] && x2!=s[1] && x2!=s[2])
            {
                cnt++;
            }
            if(x3!=s[0] && x3!=s[1] && x3!=s[2])
            {
                cnt++;
            }
            ans=min(ans,cnt);
        }
    }
    cout<<ans<<"\n";
}
signed main()
{
    sol();
    return 0;
}