#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    char cells[n][m];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>cells[i][j];
        }
    }
    int trace[n][m]={0};
    int ok=1;
    for(int i=n-1;~i;--i)
    {
        for(int j=m-1;~j;--j)
        {
            if(cells[i][j]=='*')
            {
                if(true)
                {
                    int x,i,y=j,c1=0;
                    for(;x>=0 && y>=0;)
                    {
                        if(cells[x][y]!='*')
                        {
                            return;
                        }
                        c1++,x--,y--;
                    }
                    x=i,y=i;
                    int c2=0;
                    for(;x>=0 && y<m;)
                    {
                        if(cells[x][y]!='*')
                        {
                            return;
                        }
                        c2++,x--,y++;
                    }
                    x=i,y=i;
                    int mini=min(c1,c2)-1;
                    if(k<=mini)
                    {
                        
                        for(;x>=i-mini;)
                        {
                            trace[x][y]=1,x--,y--;
                        }
                        x=i,y=j;
                        for(;x>=i-mini;)
                        {
                            trace[x][y]=1,x--,y++;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(cells[i][j]=='*' && !trace[i][j])
            {
                ok=0;
                break;
            }
        }
    }
    cout<<((ok?"YES":"NO"))<<endl;
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