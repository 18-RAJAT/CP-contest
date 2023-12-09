#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;++i)
    {
        cin>>b[i];
    }
    int matrix[n][m];
    memset(matrix,-1,sizeof(matrix));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<a[i];++j)
        {
            matrix[i][j]=1;
        }
        if(a[i]<m)
        {
            matrix[i][a[i]]=0;
        }
    }
    bool ok=true;
    for(int j=0;j<m && ok;++j)
    {
        for(int i=0;i<b[j] && ok;++i)
        {
            if(matrix[i][j]==0)
            {
                ok=false;
            }
            else
            {
                matrix[i][j]=1;
            }
        }
        if(b[j]<n)
        {
            if(matrix[b[j]][j]==1)
            {
                ok=false;
            }
            else
            {
                matrix[b[j]][j]=0;
            }
        }
    }
    if(ok)
    {
        int ans=1;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(matrix[i][j]==-1)
                {
                    ans=(ans*1LL*2)%1000000007;
                }
            }
        }
        cout<<ans<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}