#include<bits/stdc++.h>
using namespace std;
#define int long long
int color(char c)
{
    if(c=='B')
    {
        return 1;
    }
    return 0;
}
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(color(s[i]))
        {
            ans++;
            int mini=min(n,i+k);
            for(int j=i;j<mini;++j)
            {
                s[j]='W';
            }
        }
    }
    cout<<ans<<"\n";
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