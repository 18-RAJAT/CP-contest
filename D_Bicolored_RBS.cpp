#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans(n,'0');
    int res=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='(')
        {
            ans[i]='0'+(res%2),res++;
        }
        else
        {
            res--,ans[i]='0'+((res%2));
        }
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}