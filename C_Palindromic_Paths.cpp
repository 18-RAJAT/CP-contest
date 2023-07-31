#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n][m];
        memset(a,0,sizeof(a));

        vector<int>v1(n+m-1,0),v2(n+m-1,0);

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                cin>>a[i][j];
                if(a[i][j]==0)
                {
                    v1[i+j]++;
                }
                else
                {
                    v2[i+j]++;
                }
            }
        }
        int x,y,vals(n+m-2);
        int ans(0);
        for(int i=0;i<=vals/2;++i)
        {
            if((i==vals/2 && (n+m)%2==0))
            {
                continue;
            }
            else
            {
                x=v1[i]+v1[vals-i];
                y=v2[i]+v2[vals-i];
                ans+=min<int>(x,y);
            }
        }
        cout<<ans<<"\n";
    }
}