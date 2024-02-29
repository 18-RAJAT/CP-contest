#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int ans=1,tmp=-1;
    string res="";
    for(int i=0;i<n-1;++i)
    {
        if(s[i+1]=='1' && t[i]=='0')
        {
            tmp=i;
            break;
        }
    }
    if(tmp==-1)
    {
        //if no such pair found then we can reach to the end
        tmp=n-1;
    }
    int rev=0;
    for(int i=tmp;i>0;--i)
    {
        if(s[i]=='0' && t[i-1]=='1')
        {
            rev=i+1;
            break;
        }
        else
        {
            ans++;
        }
    }
    for(int i=0;i<tmp+1;++i)
    {
        res+=s[i];
    }
    for(int i=tmp;i<n;++i)
    {
        res+=t[i];
    }
    cout<<res<<endl<<ans<<endl;
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