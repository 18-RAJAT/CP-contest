#include<bits/stdc++.h>
using namespace std;
#define int long long
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void sol()
{
    int n;
    cin>>n;
    string s[2];
    cin>>s[0]>>s[1];
    int visited[2][n];
    for(int i=0;i<2;++i)
    {
        for(int j=0;j<n;++j)
        {
            visited[i][j]=0;
        }
    }
    queue<pair<int,int>>q;
    q.push({0,0});
    visited[0][0]=1;
    auto valid=[&](int x,int y,int i,int n)->bool
    {
        return x>=0 && x<i && y>=0 && y<n?true:false;
    };
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;++i)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(valid(nx,ny,2,n))
            {
                if(s[nx][ny]=='>' && ny<n)
                {
                    ny++;
                }
                else if(s[nx][ny]=='<' && ny>=1)
                {
                    ny--;
                }
                if(valid(nx,ny,2,n) && !visited[nx][ny])
                {
                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
    cout<<((visited[1][n-1])?"YES":"NO")<<endl;
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