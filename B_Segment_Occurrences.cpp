#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    string s,t;
    cin>>s>>t;
    vector<pair<int,int>>vp;
    for(int i=0;i<=n-m;++i)
    {
        int r=1;
        for(int j=0;j<m;++j)
        {
            if(s[i+j]!=t[j])
            {
                r=0;
                break;
            }
        }
        if(r==1)vp.push_back({i+1,i+m});
    }
    for(int i=0;i<k;++i)
    {
        int l,r;
        cin>>l>>r;
        int count=0;
        for(auto& it:vp)
        {
            if(l<=it.first && it.second<=r)count++;
        }
        cout<<count<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}