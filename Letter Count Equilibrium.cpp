#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    /*
        Problem statement:
        Given a lowercase word, your task is to determine whether removing exactly one letter from the word would result in each letter appearing an equal number of times. If such a letter removal is possible, return true; otherwise, return false.
        Input:
        A string representing a word consisting of lowercase letters.
        Output:
        Return true if removing one letter would result in all remaining letters having the same frequency; otherwise, return false.
        Example:
        Input1: "yummy"
        Output1: true
        Explanation: By removing the letter 'u', the word becomes "ymmy", wherein both 'y' and 'm' appear twice, achieving letter count equilibrium.
        Input2: "hello"
        Output2: false
        Explanation: No single letter removal can result in all remaining letters having the same frequency.
    */
    string s;
    cin>>s;
    map<char,int>mp;
    int n=s.size();
    if(n==1)
    {
        cout<<"true";
        return;
    }
    if(n==2)
    {
        int x=s[0]-'a';
        int y=s[1]-'a';
        if(x==y)
        {
            cout<<"true";
            return;
        }
        cout<<"false";
        return;
    }
    for(int i=0;i<n;++i)
    {
        mp[s[i]]++;
    }
    vector<pair<char,int>>v;
    while(!mp.empty())
    {
        auto it=mp.begin();
        v.push_back({it->first,it->second});
        mp.erase(it);
    }
    int cnt=0;
    for(int i=0;i<v.size();++i)
    {
        if(i==0)
        {
            if(v[i].second==1)
            {
                cnt++;
            }
        }
        else
        {
            if(v[i].second!=v[0].second)
            {
                cnt++;
            }
        }
    }
    if(cnt==1)
    {
        cout<<"true";
        return;
    }
    if(cnt==0)
    {
        cout<<"true";
        return;
    }
    cout<<"false";
}
signed main()
{
    sol();
    return 0;
}