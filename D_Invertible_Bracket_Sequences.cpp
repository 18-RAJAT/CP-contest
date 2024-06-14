#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size(),current=0,ans=0;
    map<int,int>mp;
    for(int i=1;i<n-1;++i)
    {
        char ch=s[i];
        mp[current]++;
        if(ch=='(')current++;
        else if(ch==')')current--;
    }
    mp[current]++;
    for(auto it=mp.begin();it!=mp.end();++it)
    {
        if(it->first==0 || it->first==1)
        {
            ans+=(it->second*(it->second-1)/2);
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