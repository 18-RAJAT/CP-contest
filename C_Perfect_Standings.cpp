#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    vector<int>arr(5);
    for(int i=0;i<5;++i)cin>>arr[i];
    vector<pair<int,string>>vp;
    string problems="ABCDE";
    for(int mask=1;mask<(1<<5);++mask)
    {
        string res="";
        int ans=0;
        for(int i=0;i<5;++i)
        {
            if(mask&(1<<i))
            {
                res+=problems[i];
                ans+=arr[i];
            }
        }
        vp.push_back({ans,res});
    }
    sort(vp.begin(),vp.end(),[](pair<int,string>&a,pair<int,string>&b)
    {
        if(a.first!=b.first)return a.first>b.first;
        return a.second<b.second;
    });
    for(auto& p:vp)cout<<p.second<<endl;
}
signed main()
{
    sol();
    return 0;
}