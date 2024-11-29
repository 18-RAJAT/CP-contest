#include<bits/stdc++.h>
using namespace std;
#define int long long

bool isIncreasing(vector<vector<int>>& a,vector<vector<int>>& b,int n,int m)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            int x=min(a[i][j],b[i][j]);
            int y=max(a[i][j],b[i][j]);
            if(j>0)
            {
                if (min(a[i][j-1],b[i][j-1])>=x) return false;
                if (max(a[i][j-1],b[i][j-1])>=y) return false;
            }
            if(i>0)
            {
                if (min(a[i-1][j],b[i-1][j])>=x) return false;
                if (max(a[i-1][j],b[i-1][j])>=y) return false;
            }
        }
    }
    return true;
}
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m)),b(n,vector<int>(m));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>b[i][j];
        }
    }
    cout<<(isIncreasing(a,b,n,m)?"Possible":"Impossible");
}
signed main()
{
    sol();
    return 0;
}