#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<array<int,2>>points(n);
    for(int i=0;i<n;++i)
    {
        cin>>points[i][0]>>points[i][1];
    }
    sort(points.begin(),points.end());
    int ans=0;
    for(int i=0;i<n-1;++i)
    {
        if(points[i][0]==points[i+1][0])ans+=n-2;
    }
    map<array<int,2>,int>point_occurrences;
    for(auto& it:points)
    {
        point_occurrences[it]=1;
    }
    for(int x=0;x<=n;++x)
    {
        for(int y=0;y<=1;++y)
        {
            if(point_occurrences[{x,y}] && point_occurrences[{x+1,y^1}] && point_occurrences[{x+2,y}])
            {
                ans++;
            }
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