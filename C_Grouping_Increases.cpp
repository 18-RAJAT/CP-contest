#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e18;
void sol()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<int>ans1{INF},ans2{INF};
    for(auto& it:a)
    {
        if(it<=ans1.back() && it<=ans2.back())
        {
            if(ans1.back()<ans2.back())
            {
                ans1.push_back(it);
            }
            else
            {
                ans2.push_back(it);
            }
        }
        else if(it<=ans1.back())
        {
            ans1.push_back(it);
        }
        else if(it<=ans2.back())
        {
            ans2.push_back(it);
        }
        else
        {
            if(ans1.back()<ans2.back())
            {
                ans1.push_back(it);
            }
            else
            {
                ans2.push_back(it);
            }
        }
    }
    int ans=0;
    int x=ans1.size();
    for(int i=0;i+1<x;++i)
    {
        if(ans1[i]<ans1[i+1])
        {
            ans++;
        }
    }
    int y=ans2.size();
    for(int i=0;i+1<y;++i)
    {
        if(ans2[i]<ans2[i+1])
        {
            ans++;
        }
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