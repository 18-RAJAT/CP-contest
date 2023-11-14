#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,q;
    cin>>n>>m>>q;
    int pos[1005][1005];
    memset(pos,0,sizeof(pos));
    int size=0,ctr=0;
    int check[1005];
    check[0]=0;
    size++;
    for(int i=0;i<q;++i)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            int r,c;
            cin>>r>>c;
            if(pos[r-1][c-1]==0)
            {
                // pos[r-1][c-1]=1;
                ctr++;
                // check[r-1]++;
                pos[r-1][c-1]=1;
                check[size++]=ctr;
                cout<<ctr<<endl;
            }
            else if(x==2)
            {
                cin>>x;
                for(int i=0;i<n;++i)
                {
                    if(pos[i-1][x]==1)
                    {
                        pos[i-1][x]=0;
                        ctr--;
                    }
                    else
                    {
                        pos[i-1][x]=1;
                        ctr++;
                    }
                }
                check[size++]=ctr;
                cout<<ctr<<endl;
            }
            else if(x==4)
            {
                cin>>x;
                cout<<check[x]<<endl;
            }
        }
    }
}
signed main()
{
    sol();
    return 0;
}