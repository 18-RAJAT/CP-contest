#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    int ok=0;
    for(int i=0;i<n;++i)
    {
        if(~(s[i]-'0')&1 && (s[i]-'0')<s[n-1]-'0')
        {
            ok=1,swap(s[i],s[n-1]);
            break;
        }
    }
    if(ok)cout<<s;
    else
    {
        for(int i=n-2;~i;--i)
        {
            if(~s[i]&1)
            {
                ok=1,swap(s[i],s[n-1]);
                break;
            }
        }
        if(ok)cout<<s;
        else cout<<-1;
    }
}
signed main()
{
    sol();
    return 0;
}