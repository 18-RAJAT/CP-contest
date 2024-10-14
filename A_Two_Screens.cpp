#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    int ans=0,res=0;
    for(int i=0;i<min(n,m);++i)
    {
        if(s[i]==t[i])
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    res=(n-ans)+(m-ans)+ans;
    if(ans!=0)res++;
    cout<<res<<endl;
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