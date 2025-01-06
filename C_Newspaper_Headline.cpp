#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s1,s2;
    cin>>s1>>s2;
    vector<int>pos[30];
    for(int i=0;i<s1.size();++i)pos[s1[i]-'a'].push_back(i);
    int tmp=-1,ans=1;
    for(auto& c:s2)
    {
        if(!pos[c-'a'].size())
        {
            cout<<-1;
            return;
        }
        auto it=upper_bound(pos[c-'a'].begin(),pos[c-'a'].end(),tmp);
        if(it!=pos[c-'a'].end())tmp=*it;
        else ans++,tmp=pos[c-'a'][0];
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}