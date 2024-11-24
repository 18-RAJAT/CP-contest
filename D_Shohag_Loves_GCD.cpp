#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(m);
    for(int i=0;i<m;++i)cin>>a[i];
    sort(a.begin(),a.end(),greater<int>());
    vector<int>ans(n+1,0);
    int ok=1;
    for(int j=1;j<=n && ok;++j)
    {
        vector<int>div;
        for(int d=1;d*d<=j;++d)
        {
            if(j%d==0)
            {
                if(d<j)div.push_back(d);
                if(j/d!=d && (j/d)<j)div.push_back(j/d);
            }
        }
        unordered_set<int>st;
        bool assign=false;
        for(auto& it:div)st.insert(ans[it]);
        for(auto& it:a)
        {
            if(st.find(it)==st.end())
            {
                ans[j]=it;
                assign=true;
                break;
            }
        }
        if(!assign)
        {
            ok=0;
            break;
        }
    }
    if(ok)
    {
        for(int j=1;j<=n;++j)cout<<ans[j]<<" \n"[j==n];
    }
    else cout<<-1<<endl;
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