#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1005][1005];
void sol()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>a[i][j];
        }
    }
    vector<int>ans(m);
    iota(ans.begin(),ans.end(),0);
    for(int i=0;i<m;++i)ans[i]=i;
    for(int i=0;i<n-1;++i)
    {
        vector<pair<int,int>>vp;
        for(int j=0;j<m;++j)
        {
            vp.push_back(make_pair(a[j][i]-a[j][n-1],j));
        }
        sort(vp.rbegin(),vp.rend());
        int res=0;
        set<int>st;
        for(int j=0;j<vp.size();++j)
        {
            if(res+vp[j].first>=0)
            {
                st.insert(vp[j].second);
                res+=vp[j].first;
            }
        }
        vector<int>aux;
        for(int j=0;j<m;++j)
        {
            if(!st.count(j))aux.push_back(j);
        }
        if(aux.size()<ans.size())ans=aux;
    }
    cout<<ans.size()<<endl;
    for(auto& it:ans)cout<<it+1<<" ";
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}