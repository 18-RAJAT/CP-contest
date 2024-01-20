#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<int>ans;
    ans.clear();
    ans.assign(n,0);
    for(int i=0;i<n;++i)
    {
        ans[i]=s[i]-'0';
    }
    set<int>zero,one;
    zero.clear();
    one.clear();
    for(int i=0;i<n;++i)
    {
        (ans[i]==0)?zero.insert(i+1):one.insert(i+1);
    }
    vector<vector<int>>res;
    res.clear();
    while(!zero.empty())
    {
        vector<int>temp;
        auto it=zero.begin();
        auto it1=one.upper_bound(*it);
        auto it2=zero.upper_bound(*it1);
        if(it1==one.end() || it2==zero.end())
        {
            temp.push_back(*it);
            zero.erase(it);
        }
        else if(it2==zero.end())
        {
            temp.push_back(*it);
            temp.push_back(*it1);
            one.erase(it1);
            zero.erase(it);
        }
        else if(*it2-*it1==1)
        {
            temp.push_back(*it);
            temp.push_back(*it1);
            temp.push_back(*it2);
            zero.erase(it);
            one.erase(it1);
            zero.erase(it2);
        }
        else if(*it2-*it1==2)
        {
            temp.push_back(*it);
            temp.push_back(*it1);
            temp.push_back(*it2);
            zero.erase(it);
            one.erase(it1);
            zero.erase(it2);
        }
        else if(*it2-*it1==3)
        {
            temp.push_back(*it);
            temp.push_back(*it1);
            temp.push_back(*it2);
            zero.erase(it);
            one.erase(it1);
            zero.erase(it2);
        }
        else
        {
            temp.push_back(*it);
            temp.push_back(*it1);
            temp.push_back(*it2);
            zero.erase(it);
            zero.erase(it2);
            one.erase(it1);
        }
        // cout<<"temp.size()="<<temp.size()<<endl;
        // for(int i=0;i<temp.size();++i)
        // {
        //     cout<<temp[i]<<" ";
        // }
        // cout<<endl;
        // cout<<"zero.size()="<<zero.size()<<endl;
        // cout<<"one.size()="<<one.size()<<endl;
        res.push_back(temp);
    }
    if(zero.empty() && one.empty())
    {
        cout<<res.size()<<endl;
        for(int i=0;i<res.size();++i)
        {
            cout<<res[i].size()<<" ";
            for(int j=0;j<res[i].size();++j)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<-1<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}