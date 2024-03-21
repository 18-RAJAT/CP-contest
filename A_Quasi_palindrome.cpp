#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s=to_string(n);
    auto palindrome=[&](string s)->bool
    {
        for(int i=0;i<s.size()/2;++i)
        {
            if(s[i]!=s[s.size()-1-i])
            {
                return false;
            }
        }
        return true;
    };
    int test=105;
    while(test--)
    {
        if(palindrome(s))
        {
            cout<<"YES"<<endl;
            return;
        }
        s.insert(0,1,'0');
    }
    cout<<"NO"<<endl;
}
signed main()
{
    sol();
    return 0;
}