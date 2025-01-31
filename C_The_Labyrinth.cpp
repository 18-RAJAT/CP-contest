#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1005; 
int n,m,parent[N*N],cmp[N*N];
char grid[N][N];
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
inline int Get(int i,int j){return i*m+j;}
int Find(int u)
{
    return parent[u]==u?u:parent[u]=Find(parent[u]);
}
void Union(int u,int v)
{
    int pu=Find(u),pv=Find(v);
    if(pu!=pv)
    {
        parent[pu]=pv;cmp[pv]+=cmp[pu];
    }
}
void sol()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>grid[i][j];
            int id=Get(i,j);
            parent[id]=id;
            cmp[id]=(grid[i][j]=='.')?1:0;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(grid[i][j]=='.')
            {
                for(int k=0;k<4;++k)
                {
                    int ni=i+dx[k],nj=j+dy[k];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]=='.')
                    {
                        Union(Get(i,j),Get(ni,nj));
                    }
                }
            }
        }
    }
    string ans[n];
    for(int i=0;i<n;++i)
    {
        ans[i].resize(m);
        for(int j=0;j<m;++j)
        {
            if(grid[i][j]=='.')ans[i][j]='.';
            else
            {
                unordered_set<int>st;
                int tot=1;
                for(int k=0;k<4;++k)
                {
                    int ni=i+dx[k],nj=j+dy[k];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]=='.')
                    {
                        int v=Get(ni,nj),pv=Find(v);
                        if(!st.count(pv))
                        {
                            tot+=cmp[pv];
                            st.insert(pv);
                        }
                    }
                }
                ans[i][j]='0'+(tot%10);
            }
        }
    }
    for(int i=0;i<n;++i)cout<<ans[i]<<endl;
}
signed main()
{
    sol();
    return 0;
}