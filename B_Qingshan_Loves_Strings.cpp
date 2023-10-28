#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    int c=1;
    for(int i=0;i<n-1;++i)
    {
        if(s[i]!=s[i+1])
        {
            c++;
        }
    }
    if(c==n)
    {
        puts("Yes");
        return;
    }
    c=1;
    for(int i=0;i<m-1;++i)
    {
        if(t[i]!=t[i+1])
        {
            c++;
        }
    }
    if(c!=m || t[0]!=t[m-1])
    {
        puts("No");
        return;
    }
    for(int i=0;i<n-1;++i)
    {
        if(s[i]==s[i+1] && s[i]==t[0])
        {
            puts("No");
            return;
        }
    }
    puts("Yes");
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