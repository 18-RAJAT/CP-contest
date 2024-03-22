#include<bits/stdc++.h>
using namespace std;
#define int long long
bool visited[2005][2005];
int n,m,p,q;
queue<pair<int,int>>pairs;
pair<int,int>p1,p2;
vector<array<int,2>> dir={{1,0},{-1,0},{0,1},{0,-1}};
bool check(int x,int y)
{
    return (x>=0 && x<n && y>=0 && y<m && !visited[x][y])?true:false;
}
void sol()
{
    cin>>n>>m;
    int k;
    cin>>k;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            visited[i][j]=false;
        }
    }
    for(int i=0;i<k;++i)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        p1={x,y};
        pairs.push(p1);
        visited[x][y]=true;
    }
    while(!pairs.empty())
    {
        p1=pairs.front();
        pairs.pop();
        int first_vals=p1.first,second_vals=p1.second;
        p=first_vals,q=second_vals;
        visited[first_vals][second_vals]=true;
        for(int i=0;i<4;++i)
        {
            int x=first_vals+dir[i][0],y=second_vals+dir[i][1];
            if(check(x,y))
            {
                p2={x,y};
                visited[x][y]=true;
                pairs.push(p2);
            }
        }
    }
    cout<<p+1<<" "<<q+1<<endl;
}
signed main()
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    sol();
    return 0;
}