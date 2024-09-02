#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>p(n),b(n,0),vis(n,0),ans(n);
    for(auto& it:p)
    {
        cin>>it;it--;
    }
    string s;
    cin>>s;
    for(int i=0;i<n;++i)
    {
        if(!vis[i])
        {
            int current=i;
            vector<int>chk;
            while(!vis[current])
            {
                vis[current]=1;
                chk.push_back(current);
                current=p[current];
            }
            int ert=0;
            for(auto& it:chk)
            {
                ert+=s[it]=='0';
            }
            for(auto& it:chk)
            {
                ans[it]=ert;
            }
        }
    }
    for(auto& it:ans)cout<<it<<" ";cout<<endl;
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