#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int a[n][m],b[n][m];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            char ch;
            cin>>ch;
            a[i][j]=ch-'0';
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            char ch;
            cin>>ch;
            b[i][j]=ch-'0';
        }
    }
    for(int i=0;i<n-1;++i)
    {
        for(int j=0;j<m-1;++j)
        {
            int twist=(-a[i][j]+3+b[i][j])%3;
            a[i][j]=(a[i][j]+twist)%3;
            a[i+1][j]=(a[i+1][j]+3-twist)%3;
            a[i][j+1]=(a[i][j+1]+3-twist)%3;
            a[i+1][j+1]=(a[i+1][j+1]+twist)%3;
        }
    }
    cout<<(equal(&a[0][0],&a[0][0]+n*m,&b[0][0])?"YES":"NO")<<endl;
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