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
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<a[i];++j)
        {
            matrix[i][j]=1;
        }
    }
    for(int j=0;j<m;++j)
    {
        for(int i=0;i<b[j];++i)
        {
            matrix[i][j]=1;
        }
    }
    for(int i=0;i<n;++i)
    {
        if(a[i]==m)
        {
            continue;
        }
        if(matrix[i][a[i]]==1)
        {
            cout<<0<<endl;
            return;
        }
    }
    for(int j=0;j<m;++j)
    {
        if(b[j]==n)
        {
            continue;
        }
        if(matrix[b[j]][j]==1)
        {
            cout<<0<<endl;
            return;
        }
    }
    int ans=1;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(j>a[i]&&i>b[j])
            {
                ans=ans*2%1000000007;
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}