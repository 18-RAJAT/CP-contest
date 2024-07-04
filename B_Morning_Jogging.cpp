#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;++i)sort(a[i],a[i]+m);
    for(int j=0;j<m;++j)
    {
        int ans=1e15,index=0;
        for(int i=0;i<n;++i)
        {
            if(a[i][j]<ans)
            {
                ans=a[i][j],index=i;
            }
        }
        for(int i=0;i<n;++i)
        {
            if(i!=index)
            {
                swap(a[i][j],a[i][m-1]);
                sort(a[i]+j+1,a[i]+m);
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
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