#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    map<int,set<int>>mp;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        mp[a[i]].insert(i);
    }
    vector<int>ans;
    for(int i=0;i<n;++i)
    {
        if(~a[i])
        {
            int Temp=a[i];
            while(mp[Temp].size()>1)
            {
                int First=*mp[Temp].begin();
                int Second=*next(mp[Temp].begin());
                a[Second]+=a[First];
                a[First]=-1;
                mp[Temp].erase(First);
                mp[Temp].erase(Second);
                mp[a[Second]].insert(Second);
            }
        }
    }
    for(auto &it:mp)
    {
        if(it.second.size()>1)
        {
            int Temp=*it.second.begin();
            for(auto i=next(it.second.begin());i!=it.second.end();++i)
            {
                a[*i]+=a[Temp];
                a[Temp]=-1;
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        if(~a[i])ans.push_back(a[i]);
        if(a[i]==0)mp[0].erase(i);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i]<<" ";
    }
}
signed main()
{
    sol();
    return 0;
}