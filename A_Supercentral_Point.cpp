#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>x(n),y(n);
    for(int i=0;i<n;++i)cin>>x[i]>>y[i];
    int ans=0;
    for(int i=0;i<n;++i)
    {
        bool right=0,left=0,up=0,down=0;
        for(int j=0;j<n;++j)
        {
            if(j==i)continue;
            if(x[j]==x[i])
            {
                if(y[j]>y[i])up=1;
                if(y[j]<y[i])down=1;
            }
            if(y[j]==y[i])
            {
                if(x[j]>x[i])right=1;
                if(x[j]<x[i])left=1;
            }
        }
        if(right && left && up && down)ans++;
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}