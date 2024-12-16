#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<int>b(n+1,0),c,ans;
    for(auto& it:a)if(it<=n)b[it]=1;
    for(int i=1;i<=n;++i)if(!b[i])c.push_back(i);
    unordered_set<int>st;
    int id=0;
    for(auto& it:a)
    {
        if(st.count(it)==0)
        {
            ans.push_back(it);
            st.insert(it);
        }
        else
        {
            ans.push_back(c[id++]);
        }
    }
    for(auto& it:ans)cout<<it<<" ";
    cout<<endl;
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