#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s,p;
    cin>>s>>p;
    int pos[26];
    for(int i=0;i<26;++i)pos[p[i]-'a']=i+1;
    char mp[26];
    for(int i=0;i<26;++i)
    {
        int id=pos[i];
        mp[i]=(26-id>=0 && 26-id<26)?p[26-id]:'a'+i;
    }
    vector<int>temp(26,1e9);
    char c1=s[0],c2=mp[c1-'a'];
    temp[c1-'a']=0,temp[c2-'a']=1;
    for(int i=1;i<n;++i)
    {
        vector<int>pref(26,1e9),suf(26,1e9);
        int mn=1e9;
        for(int j=0;j<26;++j)
        {
            mn=min(mn,temp[j]);
            pref[j]=mn;
        }
        char x=s[i],y=mp[x-'a'];
        if(pref[x-'a']<1e9)suf[x-'a']=pref[x-'a'];
        if(pref[y-'a']<1e9)suf[y-'a']=pref[y-'a']+1;
        temp=move(suf);
    }
    int ans=*min_element(temp.begin(),temp.end());
    cout<<(ans<1e9?ans:-1)<<endl;
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