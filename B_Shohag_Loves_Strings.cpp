#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s,ans="-1";
    cin>>s;
    int n=s.size();
    for(int i=0;i<n-1;++i)
    {
        if(s[i]==s[i+1])
        {
            ans=s.substr(i,2);
            break;
        }
    }
    int ok=0;
    auto func=[&]()->void
    {
        for(int i=0;i<n-1;++i)
        {
            if(s[i]==s[i+1])
            {
                ans=s.substr(i,2);
                ok=1;
                break;
            }
        }
    };
    func();
    if(ok){}
    else
    {
        for(int i=0;i<n-2;++i)
        {
            int f1=s[i]!=s[i+1];
            int f2=s[i]!=s[i+2];
            int f3=s[i+1]!=s[i+2];
            if(f1 && f2 && f3)
            {
                ans=s.substr(i,3);
                break;
            }
        }
    }
    cout<<ans<<endl;
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