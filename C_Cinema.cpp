#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        (mp.find(x)==mp.end())?mp[x]=1:mp[x]++;
    }
    int m;
    cin>>m;
    vector<int>b(m),c(m);
    map<int,set<int>>mp1,mp2;
    mp1.clear();
    mp2.clear();
    for(int i=0;i<m;++i)
    {
        cin>>b[i];
        mp1[b[i]].insert(i);
    }
    for(int i=0;i<m;++i)
    {
        cin>>c[i];
        mp2[c[i]].insert(i);
    }
    int maximum1=0,maximum2=0,index=0;
    for(auto& it:mp)
    {
        if(it.second>maximum1)
        {
            if(mp1.find(it.first)!=mp1.end())
            {
                maximum1=it.second;
                maximum2=0;
                if(index==0)
                {
                    index=*(mp1[it.first].begin());
                }
                for(auto& itr:mp1[it.first])
                {
                    if(mp.find(c[itr])!=mp.end())
                    {
                        if(mp[c[itr]]>maximum2)
                        {
                            maximum2=mp[c[itr]];
                            index=itr;
                        }
                    }
                }
            }
            else
            {
                if(maximum1==0)
                {
                    if(it.second>maximum2)
                    {
                        if(mp2.find(it.first)!=mp2.end())
                        {
                            maximum2=it.second;
                            index=*(mp2[it.first].begin());
                        }
                    }
                }
            }
        }
        else if(it.second==maximum1)
        {
            if(mp1.find(it.first)!=mp1.end())
            {
                for(auto itr:mp1[it.first])
                {
                    if(mp.find(c[itr])!=mp.end())
                    {
                        if(mp[c[itr]]>maximum2)
                        {
                            maximum2=mp[c[itr]];
                            index=itr;
                        }
                    }
                }
            }
        }
    }
    cout<<index+1<<'\n';
}
signed main()
{
    sol();
    return 0;
}