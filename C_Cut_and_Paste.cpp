#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
void sol()
{
    int x;
    cin>>x;
    string s;
    cin>>s;
    int ans=s.size();
    for(int i=0;i<x;++i)
    {
        int chg=(s[i]-49);
        if(s.size()<x)
        {
            string Add=s.substr(i+1);
            for(int j=0;j<chg;++j)s+=Add;
        }
        ans=(ans+(ans-i-1)*chg)%MOD;
    }
    cout<<(ans%MOD+MOD)%MOD<<endl;
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