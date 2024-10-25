#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(vector<vector<int>>&mat,int n)
{
    int ans=0;
    for(int i=n-1;~i;--i)
    {
        for(int j=n-1;~j;--j)
        {
            if(mat[i][j]>=0) continue;
            int neg=-mat[i][j];
            ans+=neg;
            for(int k=0;k<=min(i,j);++k) mat[i-k][j-k]+=neg;
        }
    }
    return ans;
}
void sol()
{
    int n;
    cin>>n;
    vector<vector<int>>mat(n,vector<int>(n));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)cin>>mat[i][j];
    }
    cout<<recur(mat,n)<<endl;
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