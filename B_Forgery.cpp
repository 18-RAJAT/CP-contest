#include<bits/stdc++.h>
using namespace std;
#define int long long
int dir[1005][1005];
void sol()
{
    int n,m;
    cin>>n>>m;
    char ch[n][m];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            dir[i][j]=0;
            cin>>ch[i][j];
        }
    }
    for(int i=0;i<n-2;++i)
    {
        for(int j=0;j<m-2;++j)
        {
            if(ch[i][j]=='#' && ch[i][j+1]=='#' && ch[i][j+2]=='#' && 
            ch[i+1][j]=='#' && ch[i+1][j+2]=='#' && ch[i+2][j]=='#' && 
            ch[i+2][j+1]=='#' && ch[i+2][j+2]=='#')
            {
                dir[i][j]=1,dir[i][j+1]=1,dir[i][j+2]=1,dir[i+1][j]=1;
                dir[i+1][j+2]=1,dir[i+2][j]=1,dir[i+2][j+1]=1,dir[i+2][j+2]=1;
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(dir[i][j]==0 && ch[i][j]=='#')
            {
                cout<<"NO";
                return;
            }
        }
    }
    cout<<"YES";
}
signed main()
{
    sol();
    return 0;
}