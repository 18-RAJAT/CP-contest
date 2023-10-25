#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int mat[n][m];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>mat[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            int arr[4]={mat[i][j],mat[n-i-1][j],mat[i][m-j-1],mat[n-i-1][m-j-1]};
            sort(arr,arr+4);
            int count=0;
            ans+=abs(mat[i][j]-arr[1]);
            ans+=abs(mat[n-i-1][j]-arr[1]);
            ans+=abs(mat[i][m-j-1]-arr[1]);
            ans+=abs(mat[n-i-1][m-j-1]-arr[1]);
            ans+=count;
        }
    }
    cout<<ans/4<<'\n';
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