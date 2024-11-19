#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(m+1);
    string s;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        for(int j=0;j<m;++j)
        {
            if(s[j]=='1')a[j+1].push_back(i);
        }
    }
    for(int i=1;i<=m;++i)sort(a[i].begin(),a[i].end());
    vector<int>all(n);
    for(int i=0;i<n;++i)all[i]=i+1;
    vector<int>ans(m+1);
    for(int i=1;i<=m;++i)
    {
        vector<int>cur;
        cur.reserve(n);
        cur=all;
        int ok=1;
        for(int j=0;j<m;++j)
        {
            int res=(i+j-1)%m+1;
            if(a[res].empty())continue;
            vector<int>tmp;
            tmp.reserve(cur.size());
            int p1=0,p2=0,x=cur.size(),y=a[res].size();
            while(p1<x && p2<y)
            {
                if(cur[p1]==a[res][p2])
                {
                    tmp.push_back(cur[p1]);
                    p1++,p2++;
                }
                else if(cur[p1]<a[res][p2])p1++;
                else p2++;
            }
            if(!tmp.empty())cur=move(tmp);
            if(cur.size()==1)
            {
                ans[i]=cur[0];ok=0;break;
            }
        }
        if(ok)ans[i]=cur[0];
    }
    for(int i=1;i<=m;++i)cout<<ans[i]<<' ';
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}