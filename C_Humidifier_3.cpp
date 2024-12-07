#include<bits/stdc++.h>
using namespace std;
#define int long long
int h,w,d;
vector<string>g;
void sol()
{
    g.resize(h);
    for(int i=0;i<h;++i)
    {
        cin>>g[i];
    }
    int dr[4]={-1,1,0,0},dc[4]={0,0,-1,1};
    vector<int>q;
    vector<char>vis(h*w,0);
    int ans=0;
    for(int i=0;i<h;++i)
    {
        for(int j=0;j<w;++j)
        {
            if(g[i][j]=='H')
            {
                int idx=i*w+j;
                if(!vis[idx])
                {
                    vis[idx]=1;
                    q.push_back(idx);
                    ans++;
                }
            }
        }
    }
    if(!ans && !d)
    {
        cout<<0<<endl;
        return;
    }
    int res=0;
    for(int k=0;k<d;++k)
    {
        int sz=q.size()-res;
        if(!sz)
        {
            break;
        }
        for(int i=res;i<res+sz;++i)
        {
            int idx=q[i],r=idx/w,c=idx%w;
            for(int j=0;j<4;++j)
            {
                int nr=r+dr[j],nc=c+dc[j];
                if(nr>=0 && nr<h && nc>=0 && nc<w && g[nr][nc]!='#')
                {
                    int tmp=nr*w+nc;
                    if(!vis[tmp])
                    {
                        vis[tmp]=1;
                        q.push_back(tmp);
                        ans++;
                    }
                }
            }
        }
        res+=sz;
    }
    cout<<ans<<endl;
}
signed main()
{
    cin>>h>>w>>d;
    sol();
    return 0;
}