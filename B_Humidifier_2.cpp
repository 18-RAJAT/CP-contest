#include<bits/stdc++.h>
using namespace std;
#define int long long
int h,w,d;
vector<string>grid;
vector<pair<int,int>>vp;
//Rajat Template
bool valid(int x,int y){return x>=0 && x<h && y>=0 && y<w;}
int dist(int x1,int y1,int x2,int y2){return abs(x1-x2)+abs(y1-y2);}
int recur(int p1,int p2)
{
    vector<vector<bool>>arr(h,vector<bool>(w,false));
    int x1=vp[p1].first,y1=vp[p1].second;
    int x2=vp[p2].first,y2=vp[p2].second;
    for(int i=0;i<h;++i)
    {
        for(int j=0;j<w;++j)
        {
            if(grid[i][j]=='#')continue;
            if(dist(i,j,x1,y1)<=d || dist(i,j,x2,y2)<=d)arr[i][j]=true;
        }
    }
    int ans=0;
    for(int i=0;i<h;++i)
    {
        for(int j=0;j<w;++j)
        {
            if(arr[i][j])ans++;
        }
    }
    return ans;
}
void sol()
{
    cin>>h>>w>>d;
    grid.resize(h);
    vp.clear();
    for(int i=0;i<h;++i)
    {
        cin>>grid[i];
        for(int j=0;j<w;++j)
        {
            if(grid[i][j]=='.')vp.push_back({i,j});
        }
    }
    int ans=0,n=vp.size();
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            ans=max(ans,recur(i,j));
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}