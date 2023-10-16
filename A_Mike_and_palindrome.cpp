#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    auto palindrome=[&](string s)->bool
    {
        int n=s.size();
        for(int i=0;i<n/2;++i)
        {
            if(s[i]!=s[n-i-1])
            {
                return false;
            }
        }
        return true;
    };
    int n=s.size();
    for(int i=0;i<26;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(s[j]-'a'==i)
            {
                continue;
            }
            string tmp=s;
            tmp[j]=i+'a';
            if(palindrome(tmp))
            {
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
}
signed main()
{
    sol();
    return 0;
}