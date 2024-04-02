#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<array<int,1000>>grid(n);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>grid[i][j];
        }
    }
    bool ok=true;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if((i-1>=0)+(i+1<n)+(j-1>=0)+(j+1<m)<grid[i][j])
            {
                ok=false;
            }
            grid[i][j]=(i-1>=0)+(i+1<n)+(j-1>=0)+(j+1<m);
        }
    }
    if(ok)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }
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