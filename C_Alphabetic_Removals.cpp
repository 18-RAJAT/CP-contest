#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s,k;
    cin>>s>>k;
    string word;cin>>word;
    map<char,int>mp;
    for(auto&it:word)
    {
        mp[it]++;
    }
    for(int i='a';i<='z';++i)
    {
        int mn=min<int>(mp[i],k);
        mp[i]-=mn;
        k-=mn;
    }
    string ans="";
    for(auto it=word.rbegin();it!=word.rend();++it)
    {
        if(mp[*it]>0)
        {
            ans+=*it;
            mp[*it]--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<"\n";
}