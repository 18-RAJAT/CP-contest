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
    for(int i=0;i<n-2;++i)
    {
        if(s[i]=='p' && s[i+1]=='i' && s[i+2]=='e')
        {
            ans++;
            s[i]='0';
            s[i+1]='0';
            s[i+2]='0';
        }
        if(s[i]=='m' && s[i+1]=='a' && s[i+2]=='p')
        {
            ans++;
            s[i]='0';
            s[i+1]='0';
            s[i+2]='0';
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