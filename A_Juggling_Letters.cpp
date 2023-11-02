#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int fz[26]={0};
    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s;
        for(auto &ch:s)
        {
            fz[ch-'a']++;
        }
    }
    for(int i=0;i<26;++i)
    {
        if(fz[i]%n!=0)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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