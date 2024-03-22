#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>a[i][j];
        }
    }
    int l=1,r=1e9;
    int ans=1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        vector<vector<int>> pre(n+1,vector<int>(n+1));
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+(a[i-1][j-1]>=mid);
            }
        }
        bool check=false;
        for(int i=0;i<=n-k;++i)
        {
            for(int j=0;j<=n-k;++j)
            {
                if(pre[i+k][j+k]-pre[i][j+k]-pre[i+k][j]+pre[i][j]>=k*k)
                {
                    check=true;
                    break;
                }
            }
            if(check)
            {
                break;
            }
        }
        if(check)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}