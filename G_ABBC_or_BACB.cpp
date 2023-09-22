#include<bits/stdc++.h>
using namespace std;
#define int long long
int maxiCoin(string s)
{
    int n=s.size();
    int ans=0;
    for(int i=0;i<n-1;++i)
    {
        if(s[i]=='A' && s[i+1]=='B')
        {
            ans++;
            i++;
        }
    }
    for(int i=0;i<n-1;++i)
    {
        if(s[i]=='B' && s[i+1]=='A')
        {
            ans++;
            i++;
        }
    }
    return ans;
}
void sol()
{
    string s;
    cin>>s;
    cout<<maxiCoin(s)<<"\n";
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