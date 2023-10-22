#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100001];
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<26;++i)
    {
        a[i]=0;
    }
    for(int i=0;i<n;++i)
    {
        a[s[i]-'a']++;
    }
    for(int i=0;i<26;++i)
    {
        if(a[i]%2!=0)
        {
            k--;
        }
    }
    if(k<-1)
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
    }
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