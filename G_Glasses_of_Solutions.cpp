#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a,b;
vector<pair<int,int>>vp;
int subset()
{
    int ans=0;
    for(int mask=1;mask<(1<<n);++mask)
    {
        int salt=0,mass=0;
        for(int i=0;i<n;++i)
        {
            if(mask&(1<<i)){
                salt+=vp[i].first;
                mass+=vp[i].second;
            }
        }
        if(mass*a==salt*b)ans++;
    }
    return ans;
}
void sol()
{
    cin>>n>>a>>b;
    vp.resize(n);
    for(int i=0;i<n;++i)cin>>vp[i].first>>vp[i].second;
    cout<<subset();
}
signed main()
{
    sol();
    return 0;
}