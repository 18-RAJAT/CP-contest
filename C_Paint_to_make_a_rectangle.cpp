#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int h,w;
    cin>>h>>w;
    vector<string>grid(h);
    for(int i=0;i<h;++i)cin>>grid[i];
    int R=h,Mr=-1,C=w,Mc=-1;
    for(int i=0;i<h;++i)
    {
        for(int j=0;j<w;++j)
        {
            if(grid[i][j]=='#')R=min(R,i),Mr=max(Mr,i),C=min(C,j),Mc=max(Mc,j);
        }
    }
    if(Mr==-1)
    {
        cout<<"No"<<endl;
        return;
    }
    for(int i=R;i<=Mr;++i)
    {
        for(int j=C;j<=Mc;++j)
        {
            if(grid[i][j]=='.')
            {
                cout<<"No"<<endl;
                return;
            }
        }
    }
    for(int i=0;i<h;++i)
    {
        for(int j=0;j<w;++j)
        {
            if(!(R<=i && i<=Mr && C<=j && j<=Mc))
            {
                if(grid[i][j]=='#')
                {
                    cout<<"No"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"Yes"<<endl;
}
signed main()
{
    sol();
    return 0;
}