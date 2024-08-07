#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s,t;
    cin>>s>>t;
    int ok=1,i=0,j=0;
    int n=s.size(),m=t.size();
    while(i<n && j<m)
    {
        if(s[i]==t[j])i++,j++;
        else if(s[i]=='?')s[i]=t[j],i++,j++;
        else i++;
    }
    if(n<=i && j<m)cout<<"NO"<<endl;
    else
    {
        for(int i=0;i<n;++i)
        {
            if(s[i]=='?')s[i]='a';
        }
        cout<<"YES"<<endl;
        cout<<s<<endl;
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