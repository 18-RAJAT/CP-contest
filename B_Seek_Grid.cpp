#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<string>s(n),t(m);
    for(int i=0;i<n;++i)cin>>s[i];
    for(int i=0;i<m;++i)cin>>t[i];
    for(int i=0;i<=n-m;++i)
    {
        for(int j=0;j<=n-m;++j)
        {
            int ok=1;
            for(int x=0;x<m;++x)
            {
                for(int y=0;y<m;++y)
                {
                    if(s[i+x][j+y]!=t[x][y])ok=0;
                }
            }
            if(ok)
            {
                cout<<i+1<<" "<<j+1<<endl;
                return;
            }
        }
    }
}
signed main()
{
    sol();
    return 0;
}