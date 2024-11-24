#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1005;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
struct State
{
    int x,y,steps,Lr,moves;
};
int n,m;
// char grid[N][N];
// bool vis[N][N][5][4];
vector<string>grid;
bool check(int x,int y)
{
    return x>=0 && x<n && y>=0 && y<m && grid[x][y]!='#';
}

int bfs(int sx,int sy,int tx,int ty)
{
    queue<State>q;
    set<tuple<int,int,int,int>>vis;
    // memset(vis,false,sizeof(vis));
    q.push({sx,sy,0,-1,0});
    // vis[sx][sy][4][0]=true;
    vis.insert({sx,sy,-1,0});
    while(!q.empty())
    {
        State cur=q.front();
        q.pop();
        if(cur.x==tx && cur.y==ty)
        {
            return cur.steps;
        }
        for(int i=0;i<4;++i)
        {
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if(check(nx,ny))
            {
                int next=(i==cur.Lr)?cur.moves+1:1;
                if(next<=3 && vis.find({nx,ny,i,next})==vis.end())
                {
                    vis.insert({nx,ny,i,next});
                    // if(next<=3 && !ert)
                    // {
                    //     ert=true;
                    // }
                    q.push({nx,ny,cur.steps+1,i,next});
                }
            }
        }
    }
    return -1;
}
void sol()
{
    cin>>n>>m;
    grid.resize(n);
    int sx,sy,tx,ty;
    for(int i=0;i<n;++i)
    {
        cin>>grid[i];
        for(int j=0;j<m;++j)
        {
            if(grid[i][j]=='S')
            {
                sx=i;
                sy=j;
            }
            else if(grid[i][j]=='T')
            {
                tx=i;
                ty=j;
            }
        }
    }
    cout<<bfs(sx,sy,tx,ty);
}
signed main()
{
    sol();
    return 0;
}