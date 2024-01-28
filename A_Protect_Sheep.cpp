#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int row,col;
    cin>>row>>col;
    char ch[row][col];
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<col;++j)
        {
            cin>>ch[i][j];
        }
    }
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<col;++j)
        {
            if(ch[i][j]=='.')
            {
                ch[i][j]='D';
            }
            else if(ch[i][j]=='S')
            {
                if(i>0)
                {
                    if(ch[i-1][j]=='W')
                    {
                        cout<<"NO"<<endl;
                        return;
                    }
                }
                if(i<row-1)
                {
                    if(ch[i+1][j]=='W')
                    {
                        cout<<"NO"<<endl;
                        return;
                    }
                }
                if(j<col-1)
                {
                    if(ch[i][j+1]=='W')
                    {
                        cout<<"NO"<<endl;
                        return;
                    }
                }
                if(j>0)
                {
                    if(ch[i][j-1]=='W')
                    {
                        cout<<"NO"<<endl;
                        return;
                    }
                }
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<col;++j)
        {
            cout<<ch[i][j];
        }
        cout<<endl;
    }   
}
signed main()
{
    sol();
    return 0;
}