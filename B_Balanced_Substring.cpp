#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    int ans=0;
    int current=0;

    map<int,int>mp;
    mp.clear();

    mp[0]=-1;

    for(int i=0;i<n;++i)
    {
        if(s[i]=='1')
        {
            current++;
        }
        else
        {
            current--;
        }
        if(mp.find(current)!=mp.end())
        {
            ans=max<int>(ans,i-mp[current]);
        }
        else
        {
            mp[current]=i;
        }
    }
    cout<<ans<<"\n";
}