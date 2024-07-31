#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    stack<int>stk;
    for(int i=0;i<n;++i)
    {
        if(i%2==0)
        {
            if(!stk.empty())
            {
                s[i]==')';
                int tp=stk.top();stk.pop();
                ans+=(i-tp);
            }
            else
            {
                s[i]='(';
                stk.push(i);
            }
        }
        else
        {
            if(s[i]=='(')
            {
                stk.push(i);
            }
            else
            {
                if(!stk.empty())
                {
                    int tp=stk.top();stk.pop();
                    ans+=(i-tp);
                }
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