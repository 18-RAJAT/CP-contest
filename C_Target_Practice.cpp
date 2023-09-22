#include<bits/stdc++.h>
using namespace std;
#define int long long
int value(int row,int col)
{
    int dr=min(row,9-row);
    int dc=min(col,9-col);
    int dist=min(dr,dc);
    if(dist==0)
    {
        return 1;
    }
    if(dist==1)
    {
        return 2;
    }
    if(dist==2)
    {
        return 3;
    }
    if(dist==3)
    {
        return 4;
    }
    return 5;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char grid[10][10];
        memset(grid,0,sizeof(grid));
        for(int i=0;i<10;++i)
        {
            for(int j=0;j<10;++j)
            {
                cin>>grid[i][j];
            }
        }
        int sum=0;
        for(int i=0;i<10;++i)
        {
            for(int j=0;j<10;++j)
            {
                if(grid[i][j]=='X')
                {
                    sum+=value(i,j);
                }
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}