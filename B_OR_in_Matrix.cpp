#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    bool a[n][m],b[n][m],mat[n][m];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>a[i][j];
            b[i][j]=0,mat[i][j]=0;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(a[i][j])
            {
                int f=0;
                for(int k=0;k<m;++k)if(!a[i][k])f=1;
                for(int k=0;k<n;++k)if(!a[k][j])f=1;
                if(!f)
                {
                    b[i][j]=1;
                    for(int k=0;k<n;++k)mat[k][j]=1;
                    for(int k=0;k<m;++k)mat[i][k]=1;
                }
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(a[i][j] && !mat[i][j])
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}