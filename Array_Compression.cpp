#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    unordered_map<int,int>mp;
    for(auto& it:a)mp[it]++;
    vector<int>ar;
    int res=0;
    for(auto& it:mp)
    {
        ar.push_back(it.second);
        res=max(res,it.second);
    }
    if(res<2)
    {
        cout<<n<<endl;
        return;
    }
    sort(ar.begin(),ar.end(),greater<int>());
    vector<int>br;
    for(auto& it:ar)
    {
        for(int x=1;x*x<=it;++x)
        {
            br.push_back(x);
            br.push_back(it/x);
        }
    }
    br.push_back(res);
    sort(br.begin(),br.end());
    br.erase(unique(br.begin(),br.end()),br.end());
    int ans=n;
    for(auto& it:br)
    {
        if(it<2 || it>res)continue;
        int s=0;
        for(auto& itr:ar)
        {
            s+=itr/it;
            if(s>=2e9)break;
        }
        if(s>=2)ans=min(ans,n-it*s+it);
    }
    cout<<ans<<endl;
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